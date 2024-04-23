#pragma once 
#include "../EM/EMConstants.hpp"
#include <Arduino.h>
//Structure to hold all recorded data and timestamp
namespace common{
    typedef struct packet{
    unsigned long time;
    EM::cartesian magData;
    double thermData;
    double voltage;
    String type;
}packet;
}
