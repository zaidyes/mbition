#include <QFile>
#include <QObject>
#include <QStringList>

class Parser : public QObject
{
    Q_OBJECT

public:
    Parser() = default;
    virtual ~Parser() = default;

    bool setFile(const QString &filePath);

    bool isValid();

    void startParsing();

    void stop();

protected:
    virtual bool parse(QString& line) = 0;

signals:
    void started();
    void finished(const QStringList &result);
    void error(const QString &error);

private:
    bool        m_stop{false};
    QFile       m_file;
};
