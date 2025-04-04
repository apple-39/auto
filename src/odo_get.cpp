
#include "odo_get/odo_get.hpp"
#include"odo_get/odo_get_config.hpp"

#include<Arduino.h>
#include<Encoder.h>

namespace ODO_GET__ODO_GET
{

    // Odo_get::Odo_get(int pin1_x ,int pin2_x) : enc_x_(pin1_x,pin2_x){}
    Odo_get::Odo_get(odo_get_config config) : enc_x_(config.pin1_x , config.pin2_x){}



}
