#include <Arduino.h>

#include "odo_get/odo_get.hpp"

ODO_GET__ODO_GET::odo_get_config config = {41,40 , 21,20};
ODO_GET__ODO_GET::Odo_get od( config );


void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);

}

void loop() {
  digitalWrite(13,1);
  od.get_x();
  od.get_y();
 
  Serial.println("");

}
