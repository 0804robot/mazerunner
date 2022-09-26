#include <corner.h>

CornerMerchantry::CornerMerchantry(int trigPin_1, int echoPin_1, int trigPin_2, int echoPin_2, float *right_threshold, float *front_threshold)
{
    set_threshold_right = right_threshold;
    set_threshold_front = front_threshold;
    this->trigPin_front = trigPin_1;
    this->echoPin_front = echoPin_1;
    this->trigPin_side = trigPin_2;
    this->echoPin_side = echoPin_2;
    pinMode(trigPin_front, OUTPUT);
    pinMode(trigPin_side, OUTPUT);
    pinMode(echoPin_front, INPUT);
    pinMode(echoPin_side, INPUT);
}
float CornerMerchantry::getDistance_front()
{
    // eliminate unknown state
    digitalWrite(trigPin_front, LOW);
    delayMicroseconds(2);
    // sending pulse
    digitalWrite(trigPin_front, HIGH);
    delayMicroseconds(10);
    // switching off pulse
    digitalWrite(trigPin_front, LOW);
    // reading pulse width and converting to distance
    float duration = pulseIn(echoPin_front, HIGH);
    return duration * 0.034 / 2;
}
float CornerMerchantry::getDistance_side()
{
    // eliminate unknown state
    digitalWrite(trigPin_side, LOW);
    delayMicroseconds(2);
    // sending pulse
    digitalWrite(trigPin_side, HIGH);
    delayMicroseconds(10);
    // switching off pulse
    digitalWrite(trigPin_side, LOW);
    // reading pulse width and converting to distance
    float duration = pulseIn(echoPin_side, HIGH);
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

    bool rightWall = wall_detected(rightDistance, *set_threshold_right);
    bool frontWall = wall_detected(frontDistance, *set_threshold_front);

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