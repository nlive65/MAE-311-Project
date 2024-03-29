#pragma once
#include "../EM/EMHandler.hpp"
#include "../THERM/THERMHandler.hpp"
#include "voltageDivider.hpp"
#include "dataPacket.hpp"
#include <Arduino.h>

namespace common{
    class sensorScheduler{
        private:
        int state;
        EM::EMHandler magReader = EM::EMHandler(4,30);
        
        //Add default params here since there is no default constructor
        THERM::THERMHandler tempReader = THERM::THERMHandler(19,4095.0,1000,4,30);
        voltageDivider redundant3v = voltageDivider(20,4095.0,1000,1000.0,4,30);

        unsigned long currentMillis;
        public:
        sensorScheduler();
        ~sensorScheduler() = default;
        int getState(){return state;};
        void setState(int newState) {state=newState;};
        void runCalibration();
        packet runDataCollection();   
        void initSensors();
        float updateGhostDist(packet data);
    };
}
