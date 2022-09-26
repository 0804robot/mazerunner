#ifndef CORNER_H
#define CORNER_H

#include <Arduino.h>

typedef enum
{
    LEFT,
    RIGHT,
    FORWARD,
    BRAKE,
} turn_direction;

class CornerMerchantry
{
private:
    bool wall_detected(float, float);
    float *set_threshold_right;
    float *set_threshold_front;
    int trigPin_front;
    int trigPin_side;
    int echoPin_front;
    int echoPin_side;

public:
    CornerMerchantry(int, int, int, int,float*, float*);
    ~CornerMerchantry();

    float getDistance_front();
    float getDistance_side();
    turn_direction getTurnDirection();
};

#endif