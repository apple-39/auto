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
    double a;//中心角[rad]
    double p;//パルス量　エンコーダの回転数みたいなもの。
    double r = 29;//半径[mm]
    double l;//孤の長さ[mm]
    double get_x() , get_y();
    
private:  
    Encoder enc_x_;
    Encoder enc_y_;
    
};
}
#endif //ODO_GET__ODO_GET_HPP