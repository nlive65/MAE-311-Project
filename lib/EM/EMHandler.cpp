#include "EMHandler.hpp"

void EM::EMHandler::initSensor(){
    magneticSensor.begin();
}

EM::cartesian EM::EMHandler::getReading(){
    magneticSensor.updateData();
    EM::cartesian field;
    field.x = magneticSensor.getX();
    field.y = magneticSensor.getY();
    field.z = magneticSensor.getZ();
    return(field);
}

void EM::EMHandler::getChauvenetCriteria(){
    basis_data.clear();
    EM::cartesian sum;
    sum.x = 0;
    sum.y = 0;
    sum.z = 0;
    while(basis_data.size() < calibrationDataSize){
        EM::cartesian nextReading = getReading();
        sum+=nextReading;
        basis_data.push_back(nextReading);
        delay(1000/frequency);
    }
    average = sum/calibrationDataSize;
    sum.x = 0;
    sum.y = 0;
    sum.z = 0;
    for(int i =0;i<calibrationDataSize;i++){
        
    }
    double c = (1-0.9)/2;
    
    cartesian Sx;
    Sx.x = pow(sum.x,0.5);
    Sx.y = pow(sum.y,0.5);
    Sx.z = pow(sum.z,0.5);
}