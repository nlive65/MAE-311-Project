#include "sensorSheduler.hpp"
#include "PodStates.hpp"
#include "PODStates.hpp"
#include "dataPacket.hpp"
#include <Arduino.h>

//Initialize both sensor hardware interfaces
void common::sensorScheduler::initSensors(){
    magReader.initSensor();
    tempReader.initSensor();
}
//On construction of the class set the state of the pod to INIT
common::sensorScheduler::sensorScheduler(){
    state = common::INIT;
}

//Function for handling data collection
common::packet common::sensorScheduler::runDataCollection(){
    //Gets the current time and builds a blank packet of data
    currentMillis = millis();
    common::packet data;
    //Sets the type to defaults
    data.type = "";
    //If it is time to get a magnetometer reading
    if(currentMillis-magReader.previousMillis  > 1000/magReader.frequency){
        //Get the reading, save the time of the reading and make the packet type reflect the collected data
        magReader.previousMillis = currentMillis;
        data.magData = magReader.getReading();
        data.time = currentMillis;
        data.type= data.type+ "mag";
    }
    //If it is time to get a thermistor reading
    if(currentMillis-tempReader.previousMillis > 1000/tempReader.frequency){
        //Get the reading, save the time of the reading and make the packet type reflect the collected data
        tempReader.previousMillis = currentMillis;
        data.thermData = tempReader.getReading();
        data.time = currentMillis;
        data.type= data.type+ "temp";
    }
    return data;
}

//Unused
void common::sensorScheduler::runCalibration(){
    
}
float common::sensorScheduler::updateGhostDist(common::packet data){
    float ghostDist = 1;

    if(tempReader.distance(data.thermData) ==3){
        //state = common::HUNT;
    }
    else if(magReader.distance(data.magData) == 3){
        //state = common::HUNT;
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