#include <Arduino.h>
#include"cytron_motor_driver_lib/motor.hpp"

cytron_motor_driver_lib::Motor motorlf(23,22),motorlb(19,18),motorrf(15,14),motorrb(36,37);




void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);

}

void loop() {
  digitalWrite(13,1);


}
