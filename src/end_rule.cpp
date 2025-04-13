#include "end_rule/end_rule.hpp"

#define  GIVE_RANGE 10
#define  TARGET_HOLD_TIME_MS 1000

namespace END_RULE
{


end_rule::end_rule(end_rule_config config) : 
motorlf(config.lf_pwm , config.lf_dir) , motorlb(config.lb_pwm , config.lb_dir) ,
motorrf(config.rf_pwm , config.rf_dir) , motorrb(config.rb_pwm , config.rb_dir)
{}


bool end_rule::judge(){

    if( cal.err_calc() < GIVE_RANGE  ){//目標地点付近か？
        if(!staying){
            stay_start_time = millis();  
            staying = 1;
        }else if(millis() - stay_start_time >= TARGET_HOLD_TIME_MS){ //一定時間が経過したか？
            staying = 0;
            end_flag = 1;
        }
    }else{
        staying = 0;
    }
    return end_flag;

}

void end_rule::active_motor(){
    
    cal.show_x_y();
    cal.output_calc();

    motorlf.drive(  -cal.output_x - cal.output_y - cal.output_z );
    motorlb.drive(  cal.output_x - cal.output_y - cal.output_z );
    motorrf.drive(  cal.output_x - cal.output_y + cal.output_z );
    motorrb.drive(  -cal.output_x - cal.output_y + cal.output_z );
  
  }
}// GETOUT

    






