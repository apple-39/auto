#include <Arduino.h>


void setup() {
  Serial.begin(115200);
  pinMode(13,OUTPUT);
}

void loop() {
  digitalWrite(13,1);

}
