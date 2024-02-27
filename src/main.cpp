/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-esp8266-input-data-html-form/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*********/
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