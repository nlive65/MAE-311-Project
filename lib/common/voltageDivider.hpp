#pragma once
#include <stdint.h>
#include <Arduino.h>
namespace common{
    class voltageDivider{
        private:
            uint8_t readPin;
            int vRef;
            int resistor1;
            int resistor2;
        public:
        voltageDivider(uint8_t analogPin, int vReference, int resistance1, int resistance2){
            readPin = analogPin;
            vRef = vReference;
            resistor1 = resistance1;
            resistor2 = resistance2;
            pinMode(readPin,INPUT);
        }
        ~voltageDivider() = default;
        double getVoltReading();
    };
}