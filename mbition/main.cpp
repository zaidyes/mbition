#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>

#include <parser/CPUInfoParser.h>

int main(int argc, char *argv[])
{
    qmlRegisterType<CPUInfoParser>("com.prototype.cpuinfoparser", 1, 0, "CPUInfoParser");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlContext *ctxt = engine.rootContext();


    CPUInfoParser cpuInfoParser;
    //ctxt->setContextProperty("cpuInfoParser", &cpuInfoParser);
    //ctxt->setContextProperty("procInfoModel", QVariant::fromValue(QStringList()));
    ctxt->setContextProperty("summary", QVariant::fromValue(cpuInfoParser.getCpuSummary()));
    ctxt->setContextProperty("procInfoModel", QVariant::fromValue(cpuInfoParser.getProcInfos()));


    QObject::connect(&cpuInfoParser, &CPUInfoParser::finished, [&]() {
       ctxt->setContextProperty("summary", QVariant::fromValue(cpuInfoParser.getCpuSummary()));
       ctxt->setContextProperty("procInfoModel", QVariant::fromValue(cpuInfoParser.getProcInfos()));
    });

   /* QObject::connect(&cpuInfoParser, &CPUInfoParser::error, [&ctxt](const QString &error) {
       ctxt->setContextProperty("parsedModel", QVariant::fromValue(QStringList() << error));
    });*/
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (cpuInfoParser.isValid()) {
        cpuInfoParser.startParsing();
    } else {
         qDebug() << cpuInfoParser.getFileName() << "cannot be read";
    }

    return app.exec();
}
