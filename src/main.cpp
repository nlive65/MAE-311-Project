#include <RemCommon.hpp>
#include <Arduino.h>


common::multiModalLogger thoth; //Egyptian God of Writing
common::sensorScheduler shane; 
void setup() {
  thoth.init_logger();
  shane.initSensors();
}

void loop() {
  switch(shane.getState()){
    case common::INIT:
    thoth.log("Initiating..");
    shane.initSensors();
    shane.setState(common::ACQUISITION); //Switched this to not run calib so we can get data
    thoth.log("Packet:t,x,y,z,T,v");
    break;
    case common::CALIB:
    common::calibrateSignal = false;
    thoth.log("Calibrating...");
    shane.runCalibration();//Break these into more discrete steps rather than a comprehensive function
    break;
    case common::ACQUISITION:
      //debounce here
      delay(500);
      //thoth.log("State: Acquisition");
      if(common::calibrateSignal){
          shane.setState(common::CALIB);
          break;
      }
      else{
        common::packet data = shane.runDataCollection();
        if(data.time){
          thoth.sendData(data);
          //thoth.sendUpdatedDistance(shane.updateGhostDist(data));
        }
      }
    break;
    default:
    shane.setState(common::INIT);
    break;
  }
}

void debounce(){
  //When button is pressed, do common::calibrateSignal=true;

}