#include <Arduino.h>
#include "getout/getout.hpp"

GETOUT::getout_config config = { 19,18 , 36,37 , 15,14 , 23,22};//lf lb rf rbの順番
GETOUT::getout end(config);

void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  end.set();
}

void loop() {
  digitalWrite(13,1);
  end.getout_switch();
  end.active_motor();

  Serial.println("");
}
