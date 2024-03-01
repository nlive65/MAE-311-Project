#include "EMHandler.hpp"

void EM::EMHandler::init_sensor(){
    magneticSensor.begin();
}

EM::cartesian EM::EMHandler::getReading(){
    EM::cartesian field;
    field.x = magneticSensor.getX();
    field.y = magneticSensor.getY();
    field.z = magneticSensor.getZ();
    return(field);
}