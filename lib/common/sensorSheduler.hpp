#pragma once
#include "../EM/EMHandler.hpp"
#include "../THERM/THERMHandler.hpp"
#include "voltageDivider.hpp"
#include <Arduino.h>

namespace common{
    class sensorScheduler{
        private:
        int state;
        EM::EMHandler magReader;
        
        //Add default params here since there is no default constructor
        THERM::THERMHandler tempReader = THERM::THERMHandler(19,4095,1000);
        voltageDivider redundant3v = voltageDivider(20,4095,1000,1000);
        public:
        sensorScheduler();
        ~sensorScheduler() = default;
        int getState(){return state;};
        void setState(int newState) {state=newState;};
        void runCalibration();
        void runDataCollection();   
        void initSensors();
    };
}