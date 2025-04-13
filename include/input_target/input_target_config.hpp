#ifndef INPUT_TARGET_CONFIG__HPP
#define INPUT_TARGET_CONFIG__HPP
#include "end_rule/end_rule_config.hpp"

namespace INPUT_TARGET//フォルダと同じ
{
struct input_target_config
{
    double phase1_x;
    double phase1_y;
    double phase1_z;

    
    double phase2_x;
    double phase2_y;
    double phase2_z;

    
    double phase3_x;
    double phase3_y;
    double phase3_z;


    double phase4_x;
    double phase4_y;
    double phase4_z;
    END_RULE::end_rule_config end_config; 
};
}
#endif //INPUT_TARGET_CONFIG
