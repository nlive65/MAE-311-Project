#include "THERMHandler.hpp"
#include "Arduino.h"

double THERM::THERMHandler::getTemp(){
    int inReading = analogRead(readPin);
    double Rtherm = resistor1*(vRef/inReading-1);
    double T = 28.54*pow(Rtherm/resistor2,3)-158.5*pow(Rtherm/resistor2,2)+474.8*(Rtherm/resistor2)-319.85;
    return T;
}