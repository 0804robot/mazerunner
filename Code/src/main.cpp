#include <Arduino.h>
#include <corner.h>
#include <motor.h>
int trigPin_1 = 12;
int echoPin_1 = 14;
int trigPin_2 = 13;
int echoPin_2 = 27;
float right_threshold = 2.2;
float front_threshold = 3.3;
CornerMerchantry cornerLogic(trigPin_1, echoPin_1, trigPin_2, echoPin_2, right_threshold, front_threshold);
MotorPins motor_pin = {23, 19, 18, 26, 33, 25};

/*motor_pin.ENA = 5;
motor_pin.IN2 = 6;
motor_pin.IN1 = 7;
motor_pin.ENB = 8;
motor_pin.IN3 = 9;
motor_pin.IN4 = 10;*/
Drive driver(motor_pin, 20, 90);

int count = 0;

void setup()
{
    Serial.begin(9600);
    driver.init();
    cornerLogic.init();

void loop()
{
    switch (cornerLogic.getTurnDirection())
    {
    case LEFT:
        driver.corner(Left);
        break;
    case RIGHT:
        driver.corner(Right);
        break;
    case FORWARD:
        driver.accelerate();
        break;
    case BRAKE:
        driver.brake();
        break;
    default:
        driver.decelerate();
        break;
    }
}