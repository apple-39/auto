#include "getout/getout.hpp"
#define  GIVE_RANGE 10

namespace GETOUT
{
    
getout::getout(getout_config config) : motorlf(config.lf_pwm , config.lf_dir) , motorlb(config.lb_pwm , config.lb_dir) ,
                               motorrf(config.rf_pwm , config.rf_dir) , motorrb(config.rb_pwm , config.rb_dir){}

void getout::set(){
    cal.set();
}

void getout::getout_switch(){
    switch (phase)
    {
    case 1:
        cal.input_calc(100 , 0 , 0);
        cal.output_calc();
        if( cal.err_calc() < GIVE_RANGE  ){
            phase += 1;
            break;
        } 

    case 2:
        cal.input_calc(100 , 100 , 0);
        cal.output_calc();
        if( cal.err_calc() < GIVE_RANGE  ){
            phase += 1;
            break;
        } 

    case 3:
        cal.input_calc(0 , 100 , 0);
        cal.output_calc();
        if( cal.err_calc() < GIVE_RANGE  ){
            phase += 1;
            break;
        }     
    
    case 4:
        cal.input_calc(0 , 0 , 0);
        cal.output_calc();
        if( cal.err_calc() < GIVE_RANGE  ){
            phase += 1;
            break;
        } 
        
    default:
        break;
    }
    
}

void getout::active_motor(){
    
  cal.show_x_y();
  
  motorlf.drive(  -cal.output_x - cal.output_y - cal.output_z );
  motorlb.drive(  cal.output_x - cal.output_y - cal.output_z );
  motorrf.drive(  cal.output_x - cal.output_y + cal.output_z );
  motorrb.drive(  -cal.output_x - cal.output_y + cal.output_z );

}
}// GETOUT

    






