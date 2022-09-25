#ifndef MOTOR_H
#define MOTOR_H

class Drive
{
private:
    /* data */
public:
    Drive(/* args */);
    ~Drive();
    void accelerate();
    void decelerate();
    void brake();
    void sharpCorner();
    void corner();
};


#endif