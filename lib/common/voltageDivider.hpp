#pragma once
#include <stdint.h>
#include <Arduino.h>
#include "calibrationHandler.hpp"
//Class that handles a voltage divider sensor
namespace common{
    //Realizes the base calibration handler with collected data of double 
    class voltageDivider:public calibrationHandler<double>{
        public:
        uint8_t readPin;//Pin to read voltage from
        double vRef;//Input voltage
        int resistor1;//First resistor resistance
        int resistor2;//Second resistor resistance
        //Constructor Sets all members to a given default
        voltageDivider(uint8_t analogPin, double vReference, int resistance1, int resistance2, double frequency,int size) : calibrationHandler(frequency,size){
            readPin = analogPin;
            vRef = vReference;
            resistor1 = resistance1;
            resistor2 = resistance2;
        }
        //Overrides the init sensor operation to run its own version of it
        virtual void initSensor() override;
        //Default destructor
        ~voltageDivider() = default;
        //Definition of the function to collect the voltage 
        double getReading();
        //Unused
        virtual void calibrate() override{};
    };
}

