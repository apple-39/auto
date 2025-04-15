#ifndef XY_CALC__XY_CALC_HPP
#define XY_CALC__XY_CALC_HPP

#include "xy_calc/xy_calc_config.hpp"
#include"gyro/gyro.hpp"
#include "odo_get/odo_get.hpp"
#include<simple_pid_lib/pid.hpp>

namespace XY_CALC
{
class CALC{
public:
    // CALC();
    GYRO gyro;
    void set();
    void input_calc(double target_x , double target_y , double target_z);
    void show_x_y();
    void output_calc();
    double output_x, output_y , output_z;
    double target_x_ , target_y_, target_z_;
private:  
    double err_x_,err_y_,err_z_;
    double pre_angle , now_angle , diff_angle;


}; //XY_CALC_
}

#endif //XY_CALC__XY_CALC_HPP