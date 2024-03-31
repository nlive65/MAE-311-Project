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

