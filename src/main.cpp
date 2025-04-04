#include <Arduino.h>

#include "odo_get/odo_get.hpp"

ODO_GET__ODO_GET::Odo_get od;

void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);

}

void loop() {
  digitalWrite(13,1);
  od.get_x(21 , 20);
  od.get_y(39 , 38);
 

  Serial.println("");

}
