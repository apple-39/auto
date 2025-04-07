#include "xy_calc/xy_calc.hpp"
#include "odo_get/odo_get.hpp"

#include<Arduino.h>
#include <simple_pid_lib/pid.hpp>


ODO_GET__ODO_GET::odo_get_config config = {41,40 , 21,20};
ODO_GET__ODO_GET::Odo_get od( config );
simple_pid_lib::PIDConfig pid_config(1.0, 0.0,0.0, 0.0, 0.0, 0.0, -1.0, 1.0);

simple_pid_lib::PID pid_x(pid_config);

namespace XY_CALC
{
    // CALC::CALC(xy_calc_config pid_config) : pid_x(config) , pid_y(config){}
    // 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 1.0

    void CALC::show_x_y(){
        od.get_x();
        od.get_y();
        Serial.println("");
    }

    void CALC::output_calc(){
        err_x_ = target_x_ - od.get_x();
        err_y_ = target_y_ - od.get_y();
        pid_x.update(err_x_);
        // pid_y.update(err_y_);
        // pid_y.update(err_y_);
    }

}// XY_CALC_




