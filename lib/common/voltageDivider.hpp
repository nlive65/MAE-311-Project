#pragma once
#include <stdint.h>
#include <Arduino.h>
namespace common{
    class voltageDivider{
        public:
        uint8_t readPin;
        double vRef;
        int resistor1;
        int resistor2;
        voltageDivider(uint8_t analogPin, double vReference, int resistance1, int resistance2){
            readPin = analogPin;
            vRef = vReference;
            resistor1 = resistance1;
            resistor2 = resistance2;
        }
        void init_divider();
        ~voltageDivider() = default;
        double getVoltReading();
    };
}