#pragma once
#include <Tlv493d.h>
#include "EMConstants.hpp"
#include "../common/calibrationHandler.hpp"
namespace EM{
    class EMHandler : public common::calibrationHandler<cartesian>{
        private:
        Tlv493d magneticSensor = Tlv493d();
        public:
        EMHandler(double frequency, int size) : common::calibrationHandler<cartesian>(frequency,size){};
        ~EMHandler() = default;
        void initSensor() override;
        cartesian getReading() override;
        void calibrate() override{};
        void getChauvenetCriteria() override;
    };
}