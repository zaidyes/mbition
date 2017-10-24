#include <QFile>
#include <QObject>
#include <QStringList>

class Parser : public QObject
{
    Q_OBJECT

public:
    Parser() = default;
    virtual ~Parser() = default;

    void setFile(const QString &filePath);

    const QString getFileName() const;

    bool isValid() const;

    void startParsing();

    QStringList getRawResult() const { return m_result; }

protected:
    virtual void parse(QString& line) = 0;

signals:
    void started();
    void finished();
    void error(const QString &error);

private:
    QFile       m_file;
    QStringList m_result;
};
