#ifndef ODO_GET__ODO_GET_HPP
#define ODO_GET__ODO_GET_HPP
#include"odo_get/odo_get_config.hpp"
#include<Encoder.h>
namespace ODO_GET__ODO_GET
{

class Odo_get{
public:
    // Odo_get(int pin1_x ,int pin2_x);
    Odo_get(odo_get_config config);
    
private:  
    Encoder enc_x_;
    
};
}
#endif //ODO_GET__ODO_GET_HPP