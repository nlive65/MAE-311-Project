#pragma once 
#include <stdint.h>
#include <cmath>
namespace EM{
    const uint8_t EMI2CADDR = 0x5E;
    typedef struct cartesian{
        double x;
        double y;
        double z;
        cartesian& operator+=(cartesian& data){
            x+=data.x;
            y+=data.y;
            z+=data.z;
            return *this;
        };
        cartesian& operator/(int data2){
            x = x/data2;
            y = y/data2;
            z = z/data2;
            return *this;
        }
    }cartesian;

   double magnitude(cartesian vec);
} 
