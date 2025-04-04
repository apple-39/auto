#include <Arduino.h>

#include "odo_get/odo_get.hpp"

ODO_GET__ODO_GET::Odo_get od(1,2);

void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);

}

void loop() {
  digitalWrite(13,1);
 
 

  Serial.println("");

}
