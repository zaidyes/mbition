#include "CPUInfoParser.h"

#include <QDebug>
#include <QString>
#include <QTextStream>

//const QString procFile{"/home/yoctoadm/Projects/mbition/build/Debug/proc_cpuinfo.txt"};
const QString procFile{"/proc/cpuinfo"};

CPUInfoParser::CPUInfoParser()
{
    setFile(procFile);
}

QVariant CPUInfoParser::getCpuSummary() const
{
    QString summary;
    for (auto itr = m_cpuInfos.begin(); itr < m_cpuInfos.end(); ++itr) {
        if(itr != m_cpuInfos.begin()) {
            summary += "\n";
        }
        summary = ("Processor: " + itr->processorName);
        summary += "\n";
        summary += ("Cores: " + QString::number(itr->cores));
    }

    return QVariant::fromValue(summary);
}

void CPUInfoParser::parse(QString &line)
{
    QStringList keyValue = line.split(":");
    if (keyValue.size() != 2) {
        return;
    }
    // remove trailing, leading or consecutive spaces.
    QString key = keyValue[0].simplified();
    QString value = keyValue[1].simplified();

    if (key == "processor") {
        ProcInfo newProc;
        newProc.processorId = value;
        newProc.rawInfo.append(key + ":" + value);
        m_procInfos.push_back(std::move(newProc));
        return;
    }

    if (key == "vendor_id") {
        m_procInfos.back().vendorId = value;
    } else if (key == "model name") {
        m_procInfos.back().modelName = value;
    } else if (key == "cpu MHz") {
        m_procInfos.back().clockSpeed = value;
    } else if (key == "cache size") {
        m_procInfos.back().cacheSize = value;
    } else if (key == "physical id") {
        m_procInfos.back().physicalId = value;
        // See if we already have this processor name else create new processor
        auto findItr = std::find_if(m_cpuInfos.begin(), m_cpuInfos.end(), [&value](const CPUInfo& cInfo) {
            return cInfo.physicalId == value;
        });

        // did not find it create a new CPUInfo
        if(findItr == m_cpuInfos.end()) {
            CPUInfo cpuInfo;
            cpuInfo.physicalId = value;
            cpuInfo.processorName = m_procInfos.back().modelName;
            cpuInfo.cores = 0;
            cpuInfo.threads = 0;
            m_cpuInfos.push_back(std::move(cpuInfo));
        }
    } else if (key == "core id") {
        m_procInfos.back().coreId = value;
        m_cpuInfos.back().cores++;
    }

    m_procInfos.back().rawInfo.append(key + ":" + value);
}
