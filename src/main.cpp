#include <RemCommon.hpp>
#include <Arduino.h>


common::multiModalLogger logger_;

void setup() {
  logger_.init_logger();
}

void loop() {
  logger_.log("Hello ", 15);
  delay(1000);
}