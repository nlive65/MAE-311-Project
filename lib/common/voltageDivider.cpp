#include "voltageDivider.hpp"
#include "Arduino.h"
#include "constants.hpp"
void common::voltageDivider::init_divider(){
    pinMode(readPin,INPUT);
}

double common::voltageDivider::getVoltReading(){
    int unitReading = analogRead(readPin);
    double inVoltage = (resistor1+resistor2)*ADC_RESOLUTION*unitReading/resistor2;
    return(inVoltage);
}
