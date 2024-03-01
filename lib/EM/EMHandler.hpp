#pragma once
#include <Tlv493d.h>
#include "EMConstants.hpp"
namespace EM{
    class EMHandler{
        private:
        Tlv493d magneticSensor = Tlv493d();
        public:
        void init_sensor();
        cartesian getReading();

    };
}