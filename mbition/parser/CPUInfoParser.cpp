#include "CPUInfoParser.h"

#include <QDebug>
#include <QString>
#include <QTextStream>

const QString PROC_FILE{"/proc/cpuinfo"};

CPUInfoParser::CPUInfoParser()
{
    setFile(PROC_FILE);
}

CPUInfoParser::~CPUInfoParser()
{
    m_procInfos.clear();
}

QString CPUInfoParser::getCpuSummary()
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

    return summary;
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
        ProcInfo *newProc = new ProcInfo(this);
        newProc->setProcessorId(value);
        newProc->getRawInfo().append(key + ":" + value);
        m_procInfos.push_back(newProc);
        return;
    }

    if (key == "vendor_id") {
        m_procInfos.back()->setVendorId(value);
    } else if (key == "model name") {
        m_procInfos.back()->setModelName(value);
    } else if (key == "cpu MHz") {
        m_procInfos.back()->setClockSpeed(value);
    } else if (key == "cache size") {
        m_procInfos.back()->setCacheSize(value);
    } else if (key == "physical id") {
        m_procInfos.back()->setPhysicalId(value);
        // See if we already have this processor name else create new processor
        auto findItr = std::find_if(m_cpuInfos.begin(), m_cpuInfos.end(), [&value](const CPUInfo& cInfo) {
            return cInfo.physicalId == value;
        });

        // did not find it create a new CPUInfo
        if(findItr == m_cpuInfos.end()) {
            CPUInfo cpuInfo;
            cpuInfo.physicalId = value;
            cpuInfo.processorName = m_procInfos.back()->getModelName();
            cpuInfo.cores = 0;
            cpuInfo.threads = 0;
            m_cpuInfos.push_back(std::move(cpuInfo));
        }
    } else if (key == "core id") {
        m_procInfos.back()->setCoreId(value);
        m_cpuInfos.back().cores++;
    }

    m_procInfos.back()->getRawInfo().append(key + ":" + value);
}
