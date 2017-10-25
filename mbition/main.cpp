#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>

#include <parser/CPUInfoParser.h>

int main(int argc, char *argv[])
{
    //qmlRegisterType<CPUInfoParser>("com.prototype.cpuinfoparser", 1, 0, "CPUInfoParser");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("parsedModel", QVariant::fromValue(QStringList()));    

    CPUInfoParser cpuInfoParser;
    ctxt->setContextProperty("cpuInfoParser", &cpuInfoParser);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    /*QObject::connect(&cpuInfoParser, &CPUInfoParser::finished, [&]() {
       QStringList result;

       std::vector<CPUInfo> cpuInfos = cpuInfoParser.getCPUInfos();
       for (auto itr = cpuInfos.begin(); itr < cpuInfos.end(); ++itr) {
          result.append("Processor: " + itr->processorName);
          result.append("Cores: " + QString::number(itr->cores));
          result.append("---------------------------------------------------");
          result.append("---------------------------------------------------");
       }

       std::vector<ProcInfo> procInfos = cpuInfoParser.getProcInfos();
       for (auto itr = procInfos.begin(); itr < procInfos.end(); ++itr) {
           result.append("ProcessorId: " + itr->processorId);
           result.append("VendorId: " + itr->vendorId);
           result.append("Clock Speed: " + itr->clockSpeed);
           result.append("Cache Size: " + itr->cacheSize);
           result.append("Core Id: " + itr->coreId);
           result.append("---------------------------------------------------");
       }

       ctxt->setContextProperty("parsedModel", QVariant::fromValue(result));
    });*/

    QObject::connect(&cpuInfoParser, &CPUInfoParser::error, [&ctxt](const QString &error) {
       ctxt->setContextProperty("parsedModel", QVariant::fromValue(QStringList() << error));
    });

    if (cpuInfoParser.isValid()) {
        cpuInfoParser.startParsing();
    } else {
         qDebug() << cpuInfoParser.getFileName() << "cannot be read";
    }

    return app.exec();
}
