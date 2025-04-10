#include "xy_calc/xy_calc.hpp"
#include "odo_get/odo_get.hpp"
#include "angle_convert/angle_convert.hpp"

#include "Adafruit_BNO055.h"

#include<Vector.h>
#include<Arduino.h>
#include <simple_pid_lib/pid.hpp>

Adafruit_BNO055 gyro = Adafruit_BNO055(-1, 0x28, &Wire1);
imu::Vector<3> euler;

ANGLE_CONVERT converter;

ODO_GET__ODO_GET::odo_get_config config = {41,40 , 21,20};
ODO_GET__ODO_GET::Odo_get od( config );
simple_pid_lib::PIDConfig pid_config(0.005, 0, 0, 0, 0.0, 0.0, -1.0, 1.0);

simple_pid_lib::PID pid_x(pid_config) , pid_y(pid_config) , pid_z(pid_config);

namespace XY_CALC
{
    // CALC::CALC(xy_calc_config pid_config) : pid_x(config) , pid_y(config){}
    // 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 1.0

    void CALC::set(){
        gyro.begin();
        Wire1.setSCL(16);
        Wire1.setSDA(17);
    }

    void CALC::show_x_y(){
        od.get_x();
        od.get_y();
    }


    void CALC::input_calc(double target_x , double target_y){
        target_x_ = target_x;
        target_y_ = target_y;
    }

    void CALC::output_calc(){
        
        euler = gyro.getVector(Adafruit_BNO055::VECTOR_EULER);

        now_angle = converter.updateAngle( euler.x() );
        err_z_ = target_z_ - now_angle;
        err_x_ = target_x_ - od.get_x();
        err_y_ = target_y_ - od.get_y();

        pid_z.update(err_z_);
        pid_x.update(err_x_);
        pid_y.update(err_y_);

        pid_z.reset_integral();
        pid_x.reset_integral();
        pid_y.reset_integral();

        output_z = pid_z.get_output();
        output_x = pid_x.get_output();
        output_y = pid_y.get_output();
        
        Serial.print("  yau角 : ");
        Serial.print(now_angle);
        
        Serial.print("      output_z :");
        Serial.print(output_z);
        Serial.print("  output_x :");
        Serial.print(output_x);
        Serial.print("  output_y :");
        Serial.print(output_y);
    }


}// XY_CALC_




