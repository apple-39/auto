#ifndef ANGLE_CONVERT_HPP
#define ANGLE_CONVERT_HPP

class ANGLE_CONVERT {
private:
    double previous_angle_;
    double cumulative_angle_;
    bool first_update_;

public:
    ANGLE_CONVERT();
    double updateAngle(double current_angle);
};

#endif // ANGLE_CONVERT_HPP