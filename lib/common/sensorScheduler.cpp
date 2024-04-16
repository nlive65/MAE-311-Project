#include "sensorSheduler.hpp"
#include "PodStates.hpp"
#include "PODStates.hpp"
#include "dataPacket.hpp"
#include <Arduino.h>
void common::sensorScheduler::initSensors(){
    magReader.initSensor();
    tempReader.initSensor();
    
}

common::sensorScheduler::sensorScheduler(){
    state = common::INIT;
}

void common::sensorScheduler::runCalibration(){
    
}
common::packet common::sensorScheduler::runDataCollection(){
    
    currentMillis = millis();
    common::packet data;
    data.type = "";
    if(currentMillis-magReader.previousMillis  > 1000/magReader.frequency){
        magReader.previousMillis = currentMillis;
        data.magData = magReader.getReading();
        Serial.println(data.magData.y);
        data.time = currentMillis;
        data.type= data.type+ "mag";
        
    }
    if(currentMillis-tempReader.previousMillis > 1000/tempReader.frequency){
        tempReader.previousMillis = currentMillis;
        data.thermData = tempReader.getReading();
        data.time = currentMillis;
        data.type= data.type+ "temp";
    }
    return data;
}


float common::sensorScheduler::updateGhostDist(common::packet data){
    float ghostDist = 1;

    if(tempReader.distance(data.thermData) ==3){
        state = common::HUNT;
    }
    else if(magReader.distance(data.magData) == 3){
        state = common::HUNT;
    }
    else{
        state =common::ACQUISITION;
    }
    // ghostDist = tempReader.getDeviations(data.thermData);
    // if(tempReader.getDeviations(data.thermData) !=0 && EM::magnitude(magReader.getDeviations(data.magData))!=0){
    //     ghostDist = 1/tempReader.getDeviations(data.thermData) + 1/EM::magnitude(magReader.getDeviations(data.magData));//tune these params
    // }
    // else if(tempReader.getDeviations(data.thermData) ==0 && EM::magnitude(magReader.getDeviations(data.magData))!=0){
    //     ghostDist = 1/EM::magnitude(magReader.getDeviations(data.magData));//tune these params
    // }
    // else{
    //     ghostDist = 1/tempReader.getDeviations(data.thermData);
    // }
    // float updatedDist = constrain(ghostDist,0,1);
    return ghostDist;
}