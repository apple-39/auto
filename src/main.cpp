#include <Arduino.h>
#include "input_target/input_target.hpp"
#include "input_target/input_target_config.hpp"
#include "end_rule/end_rule.hpp"
#include "end_rule/end_rule_config.hpp"

INPUT_TARGET::input_target_config config = {
  100, 0, 0,   // phase1_x, y, z
  100, 100, 0,     // phase2_x, y, z
  0, 100, 0,     // phase3_x, y, z
  0, 0, 0      // phase4_x, y, z
};
INPUT_TARGET::input_target coordinate(config);

END_RULE::end_rule_config config_end = {
  19,18,//lf
  36,37,//lb
  15,14,//rf
  23,22//rb
};
END_RULE::end_rule end(config_end);



void setup() {
  end.cal.set();
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  
}

void loop() {
  digitalWrite(13,1);

  coordinate.set_position();
  end.active_motor();
  
  Serial.println("");
}
