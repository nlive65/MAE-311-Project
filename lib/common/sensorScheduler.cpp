#include "sensorSheduler.hpp"
#include "PodStates.hpp"
#include "PODStates.hpp"

void common::sensorScheduler::initSensors(){
    magReader.initSensor();
    tempReader.initSensor();
    redundant3v.initSensor();
}

common::sensorScheduler::sensorScheduler(){
    state = common::INIT;
}