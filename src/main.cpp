#include <Arduino.h>
#include"cytron_motor_driver_lib/motor.hpp"

#include"xy_calc/xy_calc.hpp"


cytron_motor_driver_lib::Motor motorlf(23,22),motorlb(19,18),motorrf(15,14),motorrb(36,37);
XY_CALC::CALC cal;


void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  cal.set();
}

void loop() {
  digitalWrite(13,1);

  // cal.show_x_y();

  cal.input_calc(100,0);
  cal.output_calc();
  
  motorlf.drive(1.0 + cal.output_x + cal.output_y + cal.output_z );
  motorlb.drive(1.0 + cal.output_x + cal.output_y + cal.output_z );
  motorrf.drive(1.0 + cal.output_x + cal.output_y + cal.output_z );
  motorrb.drive(1.0 + cal.output_x + cal.output_y + cal.output_z );

  Serial.println("");


}
