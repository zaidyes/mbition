#include "Parser.h"
#include <vector>

struct ProcInfo
{
    QString processorId;
    QString vendorId;
    QString modelName;
    QString clockSpeed;
    QString cacheSize;
    QString physicalId;
    QString coreId;
    QStringList rawInfo;
};

struct CPUInfo
{
    QString physicalId;
    QString processorName;
    int cores;
    int threads;
};

class CPUInfoParser : public Parser
{
public:
    CPUInfoParser();
    ~CPUInfoParser() = default;

    std::vector<ProcInfo> getProcInfos() const {return m_procInfos;}
    std::vector<CPUInfo> getCPUInfos() const {return m_cpuInfos;}

protected:
    void parse(QString &line) final;

private:
    std::vector<CPUInfo>  m_cpuInfos;
    std::vector<ProcInfo> m_procInfos;
};
