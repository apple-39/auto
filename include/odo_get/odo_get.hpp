#ifndef ODO_GET__ODO_GET_HPP
#define ODO_GET__ODO_GET_HPP

namespace ODO_GET__ODO_GET
{
class Odo_get{
public:
    double a;//中心角[rad]
    double p;//パルス量　エンコーダの回転数みたいなもの。
    double r = 29;//半径[mm]
    double l;//孤の長さ[mm]
    void get_x(int enc_pin1 , int enc_pin2);
    void get_y(int enc_pin1 , int enc_pin2);
private:  
    
};
}
#endif //ODO_GET__ODO_GET_HPP