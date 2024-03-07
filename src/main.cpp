#include <RemCommon.hpp>
#include <Arduino.h>


common::multiModalLogger logger_;
common::sensorScheduler hades;
void setup() {
  logger_.init_logger();
  hades.initSensors();
}

void loop() {
  logger_.log("Hello ", 15);
  delay(1000);
}