#include "voltageDivider.hpp"
#include "Arduino.h"
#include "constants.hpp"
void common::voltageDivider::initSensor(){
    pinMode(readPin,INPUT);
}

double common::voltageDivider::getReading(){
    int unitReading = analogRead(readPin);
    double inVoltage = (resistor1+resistor2)*ADC_RESOLUTION*unitReading/resistor2;
    return(inVoltage);
}
