#pragma once
#include <Tlv493d.h>
#include "EMConstants.hpp"
#include "../common/calibrationHandler.hpp"
namespace EM{
    //Class to handle the magnetometer hardware interface
    class EMHandler : public common::calibrationHandler<cartesian>{
        private:
        Tlv493d magneticSensor = Tlv493d();//Library hardware interface
        //unused
        cartesian prob = {0,0,0};
        public:
        //Uses the base constructor and default destructor
        EMHandler(double frequency, int size) : common::calibrationHandler<cartesian>(frequency,size){};
        ~EMHandler() = default;
        //Definition of the init sensor for this sensor
        void initSensor() override;
        //Gets the magnetic field data
        cartesian getReading() override;
        //Unused
        void calibrate() override{};
        int distance(cartesian data);
        //void getChauvenetCriteria() override;
    };
}