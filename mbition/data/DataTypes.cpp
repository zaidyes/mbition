#include "DataTypes.h"

ProcInfo::ProcInfo(QObject *parent)
{
    this->setParent(parent);
}

QString ProcInfo::getVendorId() const
{
    return vendorId;
}

void ProcInfo::setVendorId(const QString &value)
{
    vendorId = value;
}

QString ProcInfo::getModelName() const
{
    return modelName;
}

void ProcInfo::setModelName(const QString &value)
{
    modelName = value;
}

QString ProcInfo::getClockSpeed() const
{
    return clockSpeed;
}

void ProcInfo::setClockSpeed(const QString &value)
{
    clockSpeed = value;
}

QString ProcInfo::getCacheSize() const
{
    return cacheSize;
}

void ProcInfo::setCacheSize(const QString &value)
{
    cacheSize = value;
}

QString ProcInfo::getPhysicalId() const
{
    return physicalId;
}

void ProcInfo::setPhysicalId(const QString &value)
{
    physicalId = value;
}

QString ProcInfo::getCoreId() const
{
    return coreId;
}

void ProcInfo::setCoreId(const QString &value)
{
    coreId = value;
}

QStringList &ProcInfo::getRawInfo()
{
    return rawInfo;
}

void ProcInfo::setRawInfo(const QStringList &value)
{
    rawInfo = value;
}

QString ProcInfo::getProcessorId() const
{
    return processorId;
}

void ProcInfo::setProcessorId(const QString &value)
{
    processorId = value;
}
