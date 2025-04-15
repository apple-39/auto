#include "xy_calc/xy_calc.hpp"


namespace XY_CALC
{
    ODO_GET__ODO_GET::odo_get_config config = {41,40 , 21,20};
    ODO_GET__ODO_GET::Odo_get od( config );
    simple_pid_lib::PIDConfig pid_config(0.0025, 0, 0.0000005, 0, 0.0, 0.0, -0.3, 0.3);
    simple_pid_lib::PID pid_x(pid_config) , pid_y(pid_config) , pid_z(pid_config);

    void CALC::set(){
       gyro.set();
    }

    void CALC::show_x_y(){
        od.get_x();
        od.get_y();
    }


    void CALC::input_calc(double target_x , double target_y , double target_z){
        target_x_ = target_x;
        target_y_ = target_y;
        target_z_ = target_z;
    }

    void CALC::output_calc(){

        now_angle = gyro.get_angle();
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
        
        Serial.print("      output_x :");
        Serial.print(output_x);
        Serial.print("  output_y :");
        Serial.print(output_y);
        Serial.print("   output_z :");
        Serial.print(output_z);
    }


}// XY_CALC_




