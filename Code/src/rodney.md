#include <Arduino.h>
#include <corner.h>
#include <motor.h>

int trigPin_1 = 12;
int echoPin_1 = 14;
int trigPin_2 = 13;
int echoPin_2 = 27;
float right_threshold = 24;
float front_threshold = 20.5;

CornerMerchantry cornerLogic(trigPin_1, echoPin_1, trigPin_2, echoPin_2, right_threshold, front_threshold);
MotorPins motor_pin = {23, 19, 18, 26, 33, 25};
Drive driver(motor_pin, 150, 100);

int count = 0;

turn_direction t_dir; 

void setup()
{
    Serial.begin(9600);
    driver.init();
    cornerLogic.init();
    pinMode(16, OUTPUT);
    pinMode(22, OUTPUT);
    pinMode(17, OUTPUT);
    //digitalWrite(17, HIGH);
}

turn_direction prev_position;

void loop()
{
    driver.accelerate();
    delay(7000);
    driver.corner(Left);
    driver.accelerate();
    delay(7000);
    driver.corner(Left);
    driver.accelerate();
    delay(7000);
    driver.corner(Left);
    driver.accelerate();
    delay(7000);
    driver.corner(Right);
    driver.accelerate();
    delay(7000);
    driver.corner(Left);
    driver.accelerate();
    delay(7000);
    driver.corner(Left);
    driver.accelerate();
    delay(7000);
}