#pragma once 
#include <stdint.h>
namespace EM{
    const uint8_t EM12CADDR = 0x5E;
    typedef struct cartesian{
        double x;
        double y;
        double z;
    }cartesian;
}