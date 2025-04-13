#include "input_target/input_target.hpp"


namespace INPUT_TARGET
{

    
input_target::input_target(input_target_config config) : end(config.end_config) ,target_config(config)  {}

void  input_target::set_position(){

    switch (phase)
    {
    case 1:
    end.cal.input_calc(
        target_config.phase1_x,
        target_config.phase1_y,
        target_config.phase1_z);
    break;

    case 2:
    end.cal.input_calc(
        target_config.phase2_x,
        target_config.phase2_y,
        target_config.phase2_z);
    break;

    case 3:
    end.cal.input_calc(
        target_config.phase3_x,
        target_config.phase3_y,
        target_config.phase3_z);
    break;   
    
    case 4:
    end.cal.input_calc(
        target_config.phase4_x,
        target_config.phase4_y,
        target_config.phase4_z);
    break;
        
    default:
        break;
    }

    if(end.judge()) phase += 1 ;

}

}// GETOUT

    






