#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>

#include <parser/CPUInfoParser.h>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlContext *ctxt = engine.rootContext();

    CPUInfoParser cpuInfoParser;
    /// set empty models until the file is parsed
    ctxt->setContextProperty("summary", QVariant::fromValue(cpuInfoParser.getCpuSummary()));
    ctxt->setContextProperty("procInfoModel", QVariant::fromValue(cpuInfoParser.getProcObjects()));

    /// connect relevant signal to set model once the information changes
    QObject::connect(&cpuInfoParser, &CPUInfoParser::finished, [&]() {
       ctxt->setContextProperty("summary", QVariant::fromValue(cpuInfoParser.getCpuSummary()));
       ctxt->setContextProperty("procInfoModel", QVariant::fromValue(cpuInfoParser.getProcObjects()));
    });

    /// connect our error signal. If there is any will be showed on the ui
    QObject::connect(&cpuInfoParser, &CPUInfoParser::error, [&ctxt](const QString &error) {
       ctxt->setContextProperty("summary", QVariant::fromValue(QStringList() << "Error getting information: " + error));
    });

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    /// start parsing
    if (cpuInfoParser.isValid()) {
        cpuInfoParser.startParsing();
    } else {
         qDebug() << cpuInfoParser.getFileName() << "cannot be read";
    }

    return app.exec();
}
