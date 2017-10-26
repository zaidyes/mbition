#define pragma once

#include "Parser.h"

#include <vector>

#include <QList>
#include <data/DataTypes.h>

/**
 * @brief The CPUInfoParser class
 * Specialized class to parse /proc/cpu_info and provide models for the ui
 */
class CPUInfoParser : public Parser
{
public:
    CPUInfoParser();
    ~CPUInfoParser();

    /**
     * @brief getProcInfo
     * @return a vector of ProcInfo objects with information from parsing
     */
    const std::vector<ProcInfo*>& getProcInfo() const { return m_procInfos; }

    /**
     * @brief getCPUInfos
     * @return a vector of CpuInfo objects that can be used to make summary
     */
    const std::vector<CPUInfo>& getCPUInfos() const { return m_cpuInfos; }

    /**
     * @brief getCpuSummary
     * @return a summary derived from the cpu info we parsed
     */
    QString getCpuSummary();

    /**
     * @brief getProcObjects
     * @return a QList<QObject*> style model to drive the list view
     */
    QList<QObject*> getProcObjects() {
        QList<QObject*> result;
        foreach(ProcInfo* procInfo, m_procInfos) {
            result.append(procInfo);
        }

        return result;
    }

protected:
    void parse(QString &line) final;

private:
    std::vector<CPUInfo>    m_cpuInfos;
    std::vector<ProcInfo*>  m_procInfos;
};
