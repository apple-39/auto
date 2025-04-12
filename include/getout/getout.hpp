#ifndef GETOUT_HPP
#define GETOUT_HPP

#include"getout/getout_config.hpp"
#include "xy_calc/xy_calc.hpp"
#include <cytron_motor_driver_lib/motor.hpp>

namespace GETOUT_CONFIG//フォルダと同じ
{
class getout {
public:
    getout( getout_config config);
    void set();
    void getout_switch();
    void active_motor();
    XY_CALC::CALC cal;

private:
    int phase = 0;
    cytron_motor_driver_lib::Motor motorlf,motorlb,motorrf,motorrb;

};
}
#endif // GETOUT_HPP