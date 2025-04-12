#include <Arduino.h>
#include"cytron_motor_driver_lib/motor.hpp"

#include"xy_calc/xy_calc.hpp"


cytron_motor_driver_lib::Motor motorlf(19,18),motorlb(36,37),motorrf(15,14),motorrb(23,22);
XY_CALC::CALC cal;


void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  cal.set();
}

void loop() {
  digitalWrite(13,1);

  // cal.show_x_y();

  cal.input_calc(0,100);
  cal.output_calc();
  
  motorlf.drive(  -cal.output_x - cal.output_y - cal.output_z );
  motorlb.drive(  cal.output_x - cal.output_y - cal.output_z );
  motorrf.drive(  cal.output_x - cal.output_y + cal.output_z );
  motorrb.drive(  -cal.output_x - cal.output_y + cal.output_z );

  Serial.println("");


}
