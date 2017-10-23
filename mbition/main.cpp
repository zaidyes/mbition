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
    ctxt->setContextProperty("parsedModel", QVariant::fromValue(QStringList()));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    CPUInfoParser cpuInfoParser;

    QObject::connect(&cpuInfoParser, &CPUInfoParser::finished, [&ctxt](const QStringList &result) {
       ctxt->setContextProperty("parsedModel", QVariant::fromValue(result));
    });

    QObject::connect(&cpuInfoParser, &CPUInfoParser::error, [&ctxt](const QString &error) {
       ctxt->setContextProperty("parsedModel", QVariant::fromValue(QStringList() << error));
    });

    cpuInfoParser.startParsing();

    return app.exec();
}
