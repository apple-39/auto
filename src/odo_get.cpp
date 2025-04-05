
#include "odo_get/odo_get.hpp"
#include"odo_get/odo_get_config.hpp"

#include<Arduino.h>
#include<Encoder.h>

namespace ODO_GET__ODO_GET
{

    // Odo_get::Odo_get(int pin1_x ,int pin2_x) : enc_x_(pin1_x,pin2_x){}
    Odo_get::Odo_get(odo_get_config config) : enc_x_(config.pin1_x , config.pin2_x) , enc_y_(config.pin1_y , config.pin2_y){}

    double Odo_get::get_x(){
        p = enc_x_.read();
        a = 2*PI * p/8192;
        l = r *a;
        Serial.print("x座標 : ");
        Serial.print(l);
        return l;
    }

    double Odo_get::get_y(){
        p = enc_y_.read();
        a = 2*PI * p/8192;
        l = r *a;
        Serial.print("y座標 : ");
        Serial.print(l);
        return l;

    }


}
