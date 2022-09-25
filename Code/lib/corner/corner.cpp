#include <corner.h>

CornerMerchantry::CornerMerchantry(float *right_threshold, float *front_threshold){
    set_threshold_right = right_threshold;
    set_threshold_front = front_threshold;
}

bool CornerMerchantry::wall_detected(float distance, float threshold) {
    if (distance < threshold) {
        return true;
    }else {
        return false;
    }
}

turn_direction CornerMerchantry::getTurnDirection(){
    float rightDistance = getDistance_side();
    float frontDistance = getDistance_front();

    bool rightWall = wall_detected(rightDistance, *set_threshold_right);
    bool frontWall = wall_detected(frontDistance, *set_threshold_front);

    // ROBOT MOVING AWAY FROM WALL
    if (rightWall == false && frontWall == false){
        return RIGHT;
    // ROBOT AWAY FROM WALL BUT A WALL IS IN FRONT
    }else if (rightWall == false && frontWall == true) {
        return LEFT;
    // ROBOT IS ON THE RIGHT TRACK
    }else if (rightWall == true && frontWall == false) {
        return FORWARD;
    // ROBOT IS DEFINITELY AT A CORNER
    }else if (rightWall == true && frontWall == true) {
        return LEFT;
    // IF EVERYTHING FAILS STOP
    }else{
        return BRAKE;
    }
}