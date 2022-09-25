#ifndef MOTOR_H
#define MOTOR_H

// MotorPins is the motor driver pins based on L298N motor driver
// it has ENA, IN1, IN2 for controlling one motor and
// ENB, IN3 and IN4 for controlling the other motor
struct MotorPins
{
    // Left Motor Pins
    int ENA; // ENA is used to control speed of the left motor
    int IN1; // IN1 is used to control spinning direction of the left motor
    int IN2; // IN2 is used to control spinning direction of the left motor
    // Right Motor Pins
    int ENB; // ENB is used to control speed of the right motor
    int IN3; // IN3 is used to control spinning direction of the right motor
    int IN4; // IN4 is used to control spinning direction of the right motor
};

// Direction to turn
enum Direction
{
    Left,
    Right
};
// Drive is used to drive the robot using 2 bidirectional DC motors using L298N motor driver
class Drive
{
private:
    /* data */
    // Motor driver pins
    MotorPins motor_pins;

    // Delay to wait for the robot to turn in one direction
    int turn_delay = 1000;
    // The speed of motor during turning
    int turn_speed = 125;

    // turnLeft makes the robot turns to the left direction
    void turnLeft(int turn_delay, int turn_speed);
    // turnRight makes the robot turns to the right direction
    void turnRight(int turn_delay, int turn_speed);

public:
    // Instanciates the drive class taking in the motor pins, turn delay and turn speed
    Drive(MotorPins motor_pins, int turn_delay, int turn_speed);
    ~Drive();
    void accelerate();
    void decelerate();
    void brake();
    // sharpCorner used to make a sharp corner
    void sharpCorner(Direction dir);
    // corner used to make a normal corner
    void corner(Direction dir);
    // turnOff turns off the robot
    void turnOff();
};

#endif