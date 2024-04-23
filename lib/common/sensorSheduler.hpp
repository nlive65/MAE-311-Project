#pragma once
#include "../EM/EMHandler.hpp"
#include "../THERM/THERMHandler.hpp"
#include "voltageDivider.hpp"
#include "dataPacket.hpp"
#include <Arduino.h>


//Class to hold the sensor interfaces and manage data collection
namespace common{
    class sensorScheduler{
        private:
        int state;//Current mode of the POD
        EM::EMHandler magReader = EM::EMHandler(2,31);//Magnetometer interface with frequency 2 hz and calibration size 31
        //Thermistor interface on pin 17, the input voltage in bits, the second resistor's resistance (1kohm), 
        //Frequency of 2 and calibration size 31
        THERM::THERMHandler tempReader = THERM::THERMHandler(17,4095.0,1000,2,31);
        unsigned long currentMillis;//Variable to hold current system time
        
        public:
        //Default constructor
        sensorScheduler();
        //Default destructor
        ~sensorScheduler() = default;
        //Returns the current state of the system
        int getState(){return state;};
        //Changes the state of the system 
        void setState(int newState) {state=newState;};
        //Definition for the data collection operation
        packet runDataCollection();   
        //Definition for the sensor initialization operation
        void initSensors();

        //Unused
        float updateGhostDist(packet data);
        void runCalibration();
    };
}