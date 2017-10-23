#include "Parser.h"

class CPUInfoParser : public Parser
{
  public:
    CPUInfoParser();
    ~CPUInfoParser() = default;

protected:
    virtual bool parse(QString &line);
};
