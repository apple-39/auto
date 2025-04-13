#ifndef END_RULE_HPP
#define END_RULE_HPP

#include<Arduino.h>
#include<cytron_motor_driver_lib/motor.hpp>
#include "xy_calc/xy_calc.hpp"
#include "end_rule/end_rule_config.hpp"

namespace END_RULE
{
class end_rule {
public:
    end_rule(end_rule_config config);
    bool judge();
    void active_motor();
    XY_CALC::CALC cal;

private:
    unsigned long stay_start_time = 0;  // 条件を満たし始めた時間
    bool staying , end_flag = 0;
    cytron_motor_driver_lib::Motor motorlf,motorlb,motorrf,motorrb;
};
}
#endif // END_RULE