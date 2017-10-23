#include "CPUInfoParser.h"

#include <QDebug>
#include <QString>
#include <QTextStream>

const QString procFile{"/home/yoctoadm/Projects/mbition/build/Debug/proc_cpuinfo.txt"};

CPUInfoParser::CPUInfoParser()
{
    if (!setFile(procFile)) {
        qDebug() << procFile << "cannot be read";
    }
}

bool CPUInfoParser::parse(QString &line)
{
    Q_UNUSED(line);
    return true;
}
