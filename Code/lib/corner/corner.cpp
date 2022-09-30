#include <corner.h>
#include <Arduino.h>

CornerMerchantry::CornerMerchantry(int trigPin_1, int echoPin_1, int trigPin_2, int echoPin_2, float right_threshold, float front_threshold)
{
    set_threshold_right = right_threshold;
    set_threshold_front = front_threshold;
    trigPin_front = trigPin_1;
    echoPin_front = echoPin_1;
    trigPin_side = trigPin_2;
    echoPin_side = echoPin_2;
}

void CornerMerchantry::init()
{
    pinMode(trigPin_front, OUTPUT);
    pinMode(trigPin_side, OUTPUT);
    pinMode(echoPin_front, INPUT);
    pinMode(echoPin_side, INPUT);
}

float CornerMerchantry::getDistance_front()
{
    return getDistance(trigPin_front, echoPin_front);
}
float CornerMerchantry::getDistance_side()
{
    return getDistance(trigPin_side, echoPin_side);
}

float CornerMerchantry::getDistance(int trig, int echo)
{
    // eliminate unknown state
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    // sending pulse
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    // switching off pulse
    digitalWrite(trig, LOW);
    // reading pulse width and converting to distance
    float duration = pulseIn(echo, HIGH);
    delay(30);
    return duration * 0.034 / 2;
}

bool CornerMerchantry::wall_detected(float distance, float threshold)
{
    if (distance < threshold)
    {
        return true;
    }
    else
    {
        return false;
    }
}

turn_direction CornerMerchantry::getTurnDirection()
{
    float rightDistance = getDistance_side();
    float frontDistance = getDistance_front();

    bool rightWall = wall_detected(rightDistance, set_threshold_right);
    bool frontWall = wall_detected(frontDistance, set_threshold_front);

    // ROBOT MOVING AWAY FROM WALL
    if (rightWall == false && frontWall == false)
    {
        return RIGHT;
        // ROBOT AWAY FROM WALL BUT A WALL IS IN FRONT
    }
    else if (rightWall == false && frontWall == true)
    {
        return LEFT;
        // ROBOT IS ON THE RIGHT TRACK
    }
    else if (rightWall == true && frontWall == false)
    {
        return FORWARD;
        // ROBOT IS DEFINITELY AT A CORNER
    }
    else if (rightWall == true && frontWall == true)
    {
        return LEFT;
        // IF EVERYTHING FAILS STOP
    }
    else
    {
        return BRAKE;
    }
}