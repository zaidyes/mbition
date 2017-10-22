#include "Parser.h"

class CPUInfoParser : public Parser
{
  public:
    CPUInfoParser();
    ~CPUInfoParser() = default;

    virtual void startParsing();
};
