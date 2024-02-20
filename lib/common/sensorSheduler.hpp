#pragma once
#include "../EM/EMHandler.hpp"
#include "../THERM/THERMHandler.hpp"
#include "voltageDivider.hpp"
namespace common{
    class sensorScheduler{
        private:
        int state;
        EM::EMHandler magReader;

        //Add default params here since there is no default constructor
        THERM::THERMHandler tempReader;
        voltageDivider redundant5v;
        voltageDivider redundant3v;
        public:
        sensorScheduler();
        ~sensorScheduler() = default;
        int getState(){return state;};
        void setState(int newState) {state=newState;};
        void runCalibration();
        void runDataCollection();   
        void sensorLoop();
    };
}