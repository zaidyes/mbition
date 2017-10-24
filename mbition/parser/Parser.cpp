#include "Parser.h"

#include <QtDebug>

void Parser::setFile(const QString &filePath)
{
    m_file.setFileName(filePath);
}

const QString Parser::getFileName() const
{
    return m_file.fileName();
}

bool Parser::isValid() const
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
    do {
        QString line = in.readLine();
        parse(line);
        m_result.append(line);
    } while(!in.atEnd());

    m_file.close();

    emit finished();
}

