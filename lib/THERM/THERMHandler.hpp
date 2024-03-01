#pragma once
#include <stdint.h>
#include "../common/voltageDivider.hpp"
namespace THERM{
    class THERMHandler : common::voltageDivider{
        int r25 = 1050;
        public:
        THERMHandler(uint8_t pinNum, double vReference, int resistance) : common::voltageDivider(pinNum,vReference,resistance,r25){}
        double getTemp();
    };
}