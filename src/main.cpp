#include <RemCommon.hpp>
#include <Arduino.h>


common::multiModalLogger thoth; //Creates a log handler (named after Egyptian God of writing)
common::sensorScheduler shane; //(Named after Internet Ghost Hunter Shane Madej)
void setup() {
  //Initialize all components
  thoth.init_logger();
  shane.initSensors();
}
void loop() {
  //Create a packet
  common::packet data;
  switch(shane.getState()){//Checks the state of the system
    case common::INIT:
    //If sensors need to be reinitialized
    //then initialize the sensors
    thoth.log("Initiating..");
    shane.initSensors();
    shane.setState(common::ACQUISITION); 
    thoth.log("Packet:t,x,y,z,T,v");
    break;
    case common::CALIB:
    //Debug mode is now unused
    common::calibrateSignal = false;
    shane.setState(common::ACQUISITION);
    break;
    case common::ACQUISITION:
    //unused
      if(common::calibrateSignal){
          shane.setState(common::CALIB);
          break;
      }
      else{
        //Collect data and send it
        thoth.log("State: Seeking");
        data = shane.runDataCollection();
        if(data.time){//If any piece of data was collected(don't send blank messages)
          thoth.sendData(data);
        }
      }
    break;
    default:
    //If the system state is invalid change it to initialize
    shane.setState(common::INIT);
    break;
  }
}
const int button = A1;

int buttonState;
void debounce(){
  //When button is pressed, do common::calibrateSignal=true;
  int val = digitalRead(button);
  delay (10);
  int val2 = digitalRead(button);
  if (val == val2 && val != buttonState && val == LOW) {
    common::calibrateSignal = true;
  }
  buttonState = val; 
};

