#define pragma once

#include "Parser.h"

#include <memory>
#include <vector>

#include <qqml.h>
#include <QList>
#include <data/DataTypes.h>

class CPUInfoParser : public Parser
{
    Q_OBJECT
    Q_PROPERTY(QString cpuSummary READ getCpuSummary NOTIFY summaryReady)
    //Q_PROPERTY(QVariant procInfo READ getProcInfo NOTIFY summaryReady)

public:
    CPUInfoParser();
    ~CPUInfoParser();

    QList<ProcInfo*> getProcInfo() const { return m_procInfos; }
    const std::vector<CPUInfo>& getCPUInfos() const { return m_cpuInfos; }

    QString getCpuSummary();
    QList<QObject*> getProcInfos() {
        QList<QObject*> result;
        foreach(ProcInfo* procInfo, m_procInfos) {
            result.append(procInfo);
        }

        return result;
    }


signals:
    void summaryReady(QPrivateSignal);

protected:
    void parse(QString &line) final;

private:
    std::vector<CPUInfo>    m_cpuInfos;
    QList<ProcInfo*>        m_procInfos;
};

//QML_DECLARE_TYPEINFO(CPUInfoParser, QML_HAS_ATTACHED_PROPERTIES)
