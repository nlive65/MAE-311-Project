#include <RemCommon.hpp>
#include <Arduino.h>


common::multiModalLogger thoth; //Egyptian God of Writing
common::sensorScheduler shane; // The doctor who kills Dracula
void setup() {
  thoth.init_logger();
  shane.initSensors();
}

void loop() {
  switch(shane.getState()){
    case common::INIT:
    shane.initSensors();
    shane.setState(common::CALIB);
    break;
    case common::CALIB:

    break;

    case common::AQUISITION:
    break;
  }
}