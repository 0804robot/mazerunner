#ifndef CORNER_H
#define CORNER_H

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
    bool wall_detected(float distance, float threshold);
    float getDistance(int trig, int echo);
    float *set_threshold_right;
    float *set_threshold_front;
    int trigPin_front;
    int trigPin_side;
    int echoPin_front;
    int echoPin_side;

public:
    CornerMerchantry(int trigPin_1, int echoPin_1, int trigPin_2, int echoPin_2, float *right_threshold, float *front_threshold);
    void init(void);
    float getDistance_front(void);
    float getDistance_side(void);
    turn_direction getTurnDirection(void);
};

#endif