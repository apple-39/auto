
#include "odo_get/odo_get.hpp"
#include<Arduino.h>
#include<Encoder.h>

namespace ODO_GET__ODO_GET
{
void Odo_get::get_x(int enc_pin1 , int enc_pin2)
{
    Encoder enc_x(enc_pin1,enc_pin2);
    p = enc_x.read();
    Serial.print(" x座標 ");
    Serial.print(p);
    // a = 2*3.14 * p/8192;
    // l = r *a;
    // Serial.print("x座標 : ");
    // Serial.print(l);
}

void Odo_get::get_y(int enc_pin1 , int enc_pin2)
{
    Encoder enc_y(enc_pin1,enc_pin2);
    p = enc_y.read();
    Serial.print("  y座標 ");
    Serial.print(p);
    // a = 2*3.14 * p/8192;
    // l = r *a;
    // Serial.print("y座標 : ");
    // Serial.print(l);
    // Serial.println("");
}

}
