#include "sensorSheduler.hpp"
#include "PodStates.hpp"

void common::sensorScheduler::initSensors(){
    magReader.initSensor();
    tempReader.initSensor();
    redundant3v.initSensor();
}

common::sensorScheduler::sensorScheduler(){

}