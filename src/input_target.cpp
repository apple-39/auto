#include "input_target/input_target.hpp"


namespace INPUT_TARGET
{

    
input_target::input_target(input_target_config config) : end(config.end_config) ,target_config(config)  {}

void  input_target::set_position(){

    switch (phase)
    {
    case 1:
        end.cal.input_calc(100 , 0 , 0);

    case 2:
        end.cal.input_calc(100 , 100 , 0);

    case 3:
        end.cal.input_calc(0 , 100 , 0);    
    
    case 4:
        end.cal.input_calc(0 , 0 , 0);
        
    default:
        break;
    }

    if(end.judge()) phase += 1 ;

}

}// GETOUT

    






