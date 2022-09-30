#include <Arduino.h>
#include <corner.h>
#include <motor.h>
int trigPin_1 = 1;
int echoPin_1 = 2;
int trigPin_2 = 3;
int echoPin_2 = 4;
float right_threshold = 2.2; 
float front_threshold = 3.3;
CornerMerchantry cornerLogic(trigPin_1, echoPin_1, trigPin_2, echoPin_2, right_threshold, front_threshold);
MotorPins motor_pin;
motor_pin.ENA = 5;
motor_pin.IN2 = 6;
motor_pin.IN1 = 7;
motor_pin.ENB = 8;
motor_pin.IN3 = 9;
motor_pin.IN4 = 10;
Drive driver(motor_pin, 20, 90);



void setup(){
    driver.init();
    cornerLogic.init();
}

void loop(){
    switch (cornerLogic.getTurnDirection()){
        case LEFT:
            driver.corner(LEFT);
            break;
        case RIGHT:
            driver.corner(RIGHT);
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