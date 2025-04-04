#include <Arduino.h>
#include <Encoder.h>

Encoder enc_x(21 , 20);
Encoder enc_y(39 , 38);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.print(" x座標 : ");
    Serial.print(enc_x.read());
    Serial.print(" y座標 : ");
    Serial.println(enc_y.read());
}
