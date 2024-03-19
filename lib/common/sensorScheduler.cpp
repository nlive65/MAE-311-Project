#include "sensorSheduler.hpp"
#include "PodStates.hpp"
#include "PODStates.hpp"
#include "dataPacket.hpp"
#include <Arduino.h>
void common::sensorScheduler::initSensors(){
    magReader.initSensor();
    tempReader.initSensor();
    redundant3v.initSensor();
    
}

common::sensorScheduler::sensorScheduler(){
    state = common::INIT;
}

common::packet common::sensorScheduler::runDataCollection(){
    currentMillis = millis();
    common::packet data;
    if(currentMillis-magReader.previousMillis  > 1000/magReader.frequency){
        magReader.previousMillis = currentMillis;
        data.magData = magReader.getReading();
        data.time = currentMillis;
    }
    if(currentMillis-redundant3v.previousMillis > 1000/redundant3v.frequency){
        redundant3v.previousMillis = currentMillis;
        data.voltage=redundant3v.getReading();
        data.time = currentMillis;
    }
    if(currentMillis-tempReader.previousMillis > 1000/tempReader.frequency){
        tempReader.previousMillis = currentMillis;
        data.thermData = tempReader.getReading();
        data.time = currentMillis;
    }

    return data;
}