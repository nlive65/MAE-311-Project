#include "voltageDivider.hpp"
#include "Arduino.h"
#include "constants.hpp"

//Sets the pin to read voltage from to input
void common::voltageDivider::initSensor(){
    pinMode(readPin,INPUT);
}

//Gets the voltage reading using the voltage divider equation
double common::voltageDivider::getReading(){
    int unitReading = analogRead(readPin);
    double inVoltage = (resistor1+resistor2)*ADC_RESOLUTION*unitReading/resistor2;
    return(inVoltage);
}
