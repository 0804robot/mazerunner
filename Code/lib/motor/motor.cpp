
#include "motor.h"

Drive::Drive(MotorPins motorpins, int turndelay, int turnspeed)
{
    motor_pins = motorpins;
    turn_delay = turndelay;
    turn_speed = turnspeed;
}

void Drive::init()
{
    // Set all the motor control pins to outputs
    pinMode(motor_pins.ENA, OUTPUT);
    pinMode(motor_pins.ENB, OUTPUT);
    pinMode(motor_pins.IN1, OUTPUT);
    pinMode(motor_pins.IN2, OUTPUT);
    pinMode(motor_pins.IN3, OUTPUT);
    pinMode(motor_pins.IN4, OUTPUT);

    // Turn off motors - Initial state
    turnOff();
}

void Drive::sharpCorner(Direction dir)
{
    switch (dir)
    {
    case Left:
        // Turn Right Motor in the forward direction while Left Motor is turning in backward direction
        turnLeft(turn_delay, turn_speed);
        break;
    case Right:
        // Turn Left Motor in the forward direction while Right Motor is turning in backward direction
        turnRight(turn_delay, turn_speed);
        break;
    default:
        break;
    }
}
void Drive::corner(Direction dir)
{
    switch (dir)
    {
    case Left:
        // Turn Right Motor in the forward direction while Left Motor is off
        turnLeft(turn_delay, turn_speed);
        break;
    case Right:
        // Turn Left Motor in the forward direction while Right Motor is off
        turnRight(turn_delay, turn_speed);
        break;
    default:
        break;
    }
}

void Drive::turnLeft(int turndelay, int turnspeed)
{
    digitalWrite(motor_pins.IN1, LOW);
    digitalWrite(motor_pins.IN2, LOW);
    analogWrite(motor_pins.ENA, turnspeed);
    digitalWrite(motor_pins.IN3, HIGH);
    digitalWrite(motor_pins.IN4, LOW);
    analogWrite(motor_pins.ENB, turnspeed);
    delay(turndelay);
}
void Drive::turnRight(int turndelay, int turnspeed)
{
    digitalWrite(motor_pins.IN1, HIGH);
    digitalWrite(motor_pins.IN2, LOW);
    analogWrite(motor_pins.ENA, turnspeed);
    digitalWrite(motor_pins.IN3, LOW);
    digitalWrite(motor_pins.IN4, LOW);
    analogWrite(motor_pins.ENB, turnspeed);
    delay(turndelay);
}

void Drive::turnOff()
{
    digitalWrite(motor_pins.IN1, LOW);
    digitalWrite(motor_pins.IN2, LOW);
    digitalWrite(motor_pins.IN3, LOW);
    digitalWrite(motor_pins.IN4, LOW);
}

Drive::~Drive()
{
    // Turn off motors - When exting the context of this class
    turnOff();
}

void Drive::accelerate(){}
void Drive::decelerate(){}
void Drive::brake(){}