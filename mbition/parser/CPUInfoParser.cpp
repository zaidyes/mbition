#include "CPUInfoParser.h"

#include <QDebug>
#include <QString>
#include <QTextStream>

const QString procFile{"proc_info.txt"};

CPUInfoParser::CPUInfoParser()
{
    if (setFile(procFile)) {
        qDebug() << "proc/info cannot be read";
    }
}

void CPUInfoParser::startParsing()
{
    if (!m_file.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open file";
        return;
    }

    emit started();

    QTextStream in(&m_file);

    while(!in.atEnd()) {
        if (m_stop) {
            qDebug() << "Parsing stopped";
            return;
        }

        QString line = in.readLine();
        if (!line.isEmpty()) {
            m_result.append(line);
        }
    }

    m_file.close();

    emit finished();
}
