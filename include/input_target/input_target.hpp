#ifndef INPUT_TARGET_HPP
#define INPUT_TARGET_HPP

#include<Arduino.h>
#include "end_rule/end_rule.hpp"
#include "input_target/input_target_config.hpp"

namespace INPUT_TARGET//フォルダと同じ
{
class input_target {
public:
    input_target(input_target_config config);
    void set_position();
    END_RULE::end_rule end;
private:
    int phase = 1;
    input_target_config target_config; 
};
}
#endif // INPUT_TARGET_HPP