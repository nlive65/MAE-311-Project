#pragma once 
#include <stdint.h>
namespace EM{
    const uint8_t EMI2CADDR = 0x5E;
    typedef struct cartesian{
        double x;
        double y;
        double z;
        cartesian& operator=(double a){
        x = a;
        y = a;
        z = a;
        return *this;
    }
    }cartesian;

   
} 