#pragma once 
#include "../EM/EMConstants.hpp"
namespace common{
    typedef struct packet{
    unsigned long time;
    EM::cartesian magData;
    double thermData;
    double voltage;
}packet;
}
