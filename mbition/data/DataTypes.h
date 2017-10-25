#pragma once

#include <QString>
#include <QStringList>
#include <QObject>

struct CPUInfo
{
    QString physicalId;
    QString processorName;
    int cores;
    int threads;
};

class ProcInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString processorId READ getProcessorId)
    Q_PROPERTY(QString vendorID READ getVendorId)
    Q_PROPERTY(QString modelName READ getModelName)
    Q_PROPERTY(QString clockSpeed READ getClockSpeed)
    Q_PROPERTY(QString cacheSize READ getCacheSize)
    Q_PROPERTY(QString physicalId READ getPhysicalId)
    Q_PROPERTY(QString coreId READ getCoreId)
    Q_PROPERTY(QStringList rawInfo READ getRawInfo)

public:

    ProcInfo(QObject* parent = 0);
    virtual ~ProcInfo() = default;

    QString getProcessorId() const;
    void setProcessorId(const QString &value);

    QString getVendorId() const;
    void setVendorId(const QString &value);

    QString getModelName() const;
    void setModelName(const QString &value);

    QString getClockSpeed() const;
    void setClockSpeed(const QString &value);

    QString getCacheSize() const;
    void setCacheSize(const QString &value);

    QString getPhysicalId() const;
    void setPhysicalId(const QString &value);

    QString getCoreId() const;
    void setCoreId(const QString &value);

    QStringList& getRawInfo();
    void setRawInfo(const QStringList &value);

private:

    QString processorId;
    QString vendorId;
    QString modelName;
    QString clockSpeed;
    QString cacheSize;
    QString physicalId;
    QString coreId;
    QStringList rawInfo;
};
