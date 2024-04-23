#include "THERMHandler.hpp"
#include "Arduino.h"
#include <cmath>
#include "../common/constants.hpp"


double THERM::THERMHandler::getReading() {
    //Uses the polynomial from the datasheet and the calculated calibration curve to give the temperature
    int inReading = analogRead(readPin);
    double Rtherm = inReading*resistor1/(vRef-inReading);
    double T = 28.54*pow(Rtherm/r25,3)-158.5*pow(Rtherm/r25,2)+474.8*(Rtherm/r25)-319.85;
    double calibCurve = (T+4.07)/0.702;
    return calibCurve;
}

//Unused
int THERM::THERMHandler::distance(double reading){
    if(common::THERM_TV){
        if(abs(common::THERM_TV - reading) > 5){
            return 3;
        }
    }
    else {
        return 2;
    }
}

// double THERM::THERMHandler::getDeviations(double reading){
//     if(abs(reading - common::THERM_TV) > 5){
//         if(prob >0){
//             prob-=0.1;
//         }
//     }  
//     else{
//         if(prob<1){
//             prob+=0.1;
//         }
//     }
//     return prob;
// }