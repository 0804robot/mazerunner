#ifndef CORNER_H
#define CORNER_H

// possible motor movements.
typedef enum
{
    LEFT,
    RIGHT,
    FORWARD,
    BRAKE,
    NOWALLS,
} turn_direction;

// Object created able to process distance and generate required movement
class CornerMerchantry
{
private:
    // check if the robot is close to the wall
    bool wall_detected(float distance, float threshold);
    // get distance from an ultrasonic sensor by using the trig and echo pins
    float getDistance(int trig, int echo);
    // set threshold to the wall from the right
    float set_threshold_right;
    // set threshold to the wall from the front
    float set_threshold_front;
    // ULtrasonic pins
    int trigPin_front;
    int trigPin_side;
    int echoPin_front;
    int echoPin_side;

public:
    // class constructor. Assigns ultrasoni pins and sets threshold
    CornerMerchantry(int trigPin_1, int echoPin_1, int trigPin_2, int echoPin_2, float right_threshold, float front_threshold);
    // initialises ultrasonic pins
    void init(void);
    // returns distance from the front facing ultrasonic sensor
    float getDistance_front(void);
    // returns distance from the side facing ultrasonic sensor
    float getDistance_side(void);
    // returns the required robot turn direction
    turn_direction getTurnDirection(void);
};

#endif