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

    if (!m_file.isReadable()) {
        qDebug() << "Cannot open file";
        return false;
    }

    return true;
}

void Parser::stop()
{
    m_stop = true;
}

QStringList Parser::getResult()
{
    return m_result;
}
