#include "THERMHandler.hpp"
#include "Arduino.h"

double THERM::THERMHandler::getReading() {
    int inReading = analogRead(readPin);
    double Rtherm = resistor1*(vRef/inReading-1);
    double T = 28.54*pow(Rtherm/r25,3)-158.5*pow(Rtherm/r25,2)+474.8*(Rtherm/r25)-326.85;
    return T;
}