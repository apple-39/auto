#include <Arduino.h>
#include"cytron_motor_driver_lib/motor.hpp"

#include"xy_calc/xy_calc.hpp"


cytron_motor_driver_lib::Motor motorlf(23,22),motorlb(19,18),motorrf(15,14),motorrb(36,37);
XY_CALC::CALC calc;


void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  calc.set();
}

void loop() {
  digitalWrite(13,1);

  // calc.show_x_y();

  calc.input_calc(100,0);
  calc.output_calc();
  
  motorlf.drive(1.0 + calc.output_x + calc.output_y + calc.output_z );
  motorlb.drive(1.0 + calc.output_x + calc.output_y + calc.output_z );
  motorrf.drive(1.0 + calc.output_x + calc.output_y + calc.output_z );
  motorrb.drive(1.0 + calc.output_x + calc.output_y + calc.output_z );

  Serial.println("");


}
