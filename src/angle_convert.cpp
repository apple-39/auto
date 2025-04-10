#include "angle_convert/angle_convert.hpp"

ANGLE_CONVERT::ANGLE_CONVERT() : previous_angle_(0.0), cumulative_angle_(0.0), first_update_(true) {}

double ANGLE_CONVERT::updateAngle(double current_angle) {
    if (first_update_) {
        previous_angle_ = current_angle;
        first_update_ = false;
        return cumulative_angle_;
    }

    double delta_angle = current_angle - previous_angle_;

    // 右回転で0 -> 359 のような大きな負のジャンプを補正
    if (delta_angle > 180.0) {
        delta_angle -= 360.0;
    }
    // 左回転で 359 -> 0 のような大きな正のジャンプを補正
    else if (delta_angle < -180.0) {
        delta_angle += 360.0;
    }

    cumulative_angle_ += delta_angle;
    previous_angle_ = current_angle;
    return cumulative_angle_;
}