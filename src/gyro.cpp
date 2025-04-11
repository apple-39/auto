#include "gyro/gyro.hpp"

void GYRO::set(){
    gyro.begin();
    Wire1.setSCL(16);
    Wire1.setSDA(17);
}

double GYRO::get_angle(){
    euler = gyro.getVector(Adafruit_BNO055::VECTOR_EULER);
    return converter.updateAngle( euler.x() );
}
