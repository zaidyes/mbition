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

    virtual void startParsing() = 0;

    void stop();

    virtual QStringList getResult();

signals:
    void started();
    void finished();

protected:
    bool        m_stop{false};
    QFile       m_file;
    QStringList m_result;
};
