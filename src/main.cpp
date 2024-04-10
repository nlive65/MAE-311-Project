#include <RemCommon.hpp>
#include <Arduino.h>
#include <stdint.h>
  const int button = A1;

int buttonState;
unsigned long previousMillis = 0;
unsigned long currentMillis = 50;


common::multiModalLogger thoth; //Egyptian God of Writing
common::sensorScheduler shane; 
void setup() {
  thoth.init_logger();
  shane.initSensors();
  pinMode(button, INPUT);
  buttonState = digitalRead(button);
}

void loop() {
  switch(shane.getState()){
    case common::INIT:
    shane.initSensors();
    shane.setState(common::CALIB);
    break;
    case common::CALIB:
    common::calibrateSignal = false;
    thoth.log("Calibrating...");
    shane.runCalibration();//Break these into more discrete steps rather than a comprehensive function
    break;

    case common::ACQUISITION:
      //debounce here
      if ((millis() - currentMillis) > previousMillis) {
        previousMillis = currentMillis;
      }
      if(common::calibrateSignal){
          shane.setState(common::CALIB);
          break;
      }
      else{
        common::packet data = shane.runDataCollection();
        if(data.time){
          thoth.sendData(data);
          thoth.sendUpdatedDistance(shane.updateGhostDist(data));
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
  int val = digitalRead(button);
  delay (10);
  int val2 = digitalRead(button);
  if (val == val2 && val != buttonState && val == LOW) {
    common::calibrateSignal = true;
  }
  buttonState = val;
}
