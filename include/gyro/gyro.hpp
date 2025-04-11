#ifndef GYRO_HPP
#define GYRO_HPP

#include "Adafruit_BNO055.h"
#include<Vector.h>
#include "angle_convert/angle_convert.hpp"


class GYRO {
public:
    Adafruit_BNO055 gyro = Adafruit_BNO055(-1, 0x28, &Wire1);
    imu::Vector<3> euler;
    ANGLE_CONVERT converter;
    void set();
    double get_angle(); 

private:

};

#endif // GYRO_HPP