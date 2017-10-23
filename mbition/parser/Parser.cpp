#include "Parser.h"

#include <QtDebug>

bool Parser::setFile(const QString &filePath)
{
    m_stop = false;

    if (filePath.isEmpty()) {
        qDebug() << "File path is empty";
        return false;
    }

    m_file.setFileName(filePath);

    if (!m_file.exists()) {
        qDebug() << "File does not exist";
        return false;
    }

    return true;
}

bool Parser::isValid()
{
    return m_file.exists();
}

void Parser::startParsing()
{
    if (!m_file.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open file";
        emit error("Cannot open file");
        return;
    }

    emit started();

    QTextStream in(&m_file);
    QStringList result;
    while(!in.atEnd()) {
        if (m_stop) {
            qDebug() << "Parsing stopped";
            emit error("Parsing stopped");
            return;
        }

        QString line = in.readLine();
        if (parse(line)) {
            result.append(line);
        }
    }

    m_file.close();

    emit finished(result);
}

void Parser::stop()
{
    m_stop = true;
}

