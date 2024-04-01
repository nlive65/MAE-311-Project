#include "THERMHandler.hpp"
#include "Arduino.h"

double THERM::THERMHandler::getReading() {
    int inReading = analogRead(readPin);
    double Rtherm = resistor1*(vRef/inReading-1);
    double T = 28.54*pow(Rtherm/r25,3)-158.5*pow(Rtherm/r25,2)+474.8*(Rtherm/r25)-326.85;
    return T;
}
//need to unit test this
void THERM::THERMHandler::getChauvenetCriteria(){
    basis_data.clear();
    double sum = 0;
    while(basis_data.size() <calibrationDataSize){
        double nextReading = getReading();
        sum+=nextReading;
        basis_data.push_back(nextReading);
        delay(1000/frequency);
    }
    average = sum/calibrationDataSize;
    sum = 0;
    for(int i=0;i<calibrationDataSize;i++){
        sum+= pow(basis_data[i]-average,2);
    }
    sum = sum/(calibrationDataSize-1);
    double c =  (1-0.9)/2;

    double Sx = pow(sum,0.5);
    double rejectable = 0.26*Sx;//might be the wrong magic number
    lowerDeviation = average-rejectable;
    upperDeviation = average+rejectable;
}