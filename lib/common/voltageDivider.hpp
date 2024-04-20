#pragma once
#include <stdint.h>
#include <Arduino.h>
#include "calibrationHandler.hpp"
namespace common{
    class voltageDivider:public calibrationHandler<double>{
        public:
        uint8_t readPin;
        double vRef;
        int resistor1;
        int resistor2;
        voltageDivider(uint8_t analogPin, double vReference, int resistance1, int resistance2, double frequency,int size) : calibrationHandler(frequency,size){
            readPin = analogPin;
            vRef = vReference;
            resistor1 = resistance1;
            resistor2 = resistance2;
        }
        virtual void initSensor() override;
        ~voltageDivider() = default;
        double getReading();
        virtual void calibrate() override{};
    };
}

