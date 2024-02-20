#pragma once
#include <stdint.h>
#include "../common/voltageDivider.hpp"
namespace THERM{
    class THERMHandler: common::voltageDivider{
        public:
        THERMHandler(uint8_t analogPin, int vReference, int resistance1);
        double getTemp();
    };
}