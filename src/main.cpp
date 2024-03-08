#include <RemCommon.hpp>
#include <Arduino.h>


common::multiModalLogger thoth;
common::sensorScheduler helsing;
void setup() {
  thoth.init_logger();
  helsing.initSensors();
}

void loop() {
  thoth.log("Hello ", 15);
  delay(1000);
}