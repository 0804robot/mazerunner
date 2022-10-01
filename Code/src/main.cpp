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
Drive driver(motor_pin, 50, 150);

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
    t_dir = cornerLogic.getTurnDirection();

    if (t_dir == NOWALLS) {
        t_dir = prev_position;
    }

    switch (t_dir)
    {
    case LEFT:
        prev_position = LEFT;
        driver.corner(Left);
        digitalWrite(16, HIGH);
        digitalWrite(17, LOW);
        digitalWrite(22, LOW);
        break;
    case RIGHT:
        prev_position = RIGHT;
        driver.corner(Right);
        digitalWrite(16, LOW);
        digitalWrite(17, HIGH);
        digitalWrite(22, LOW);
        break;
    case FORWARD:
        prev_position = FORWARD;
        driver.accelerate();
        digitalWrite(16, LOW);
        digitalWrite(17, LOW);
        digitalWrite(22, HIGH);
        break;
    case BRAKE:
        prev_position = BRAKE;
        driver.brake();
        break;
    case NOWALLS:
        
            break;
    default:
        driver.decelerate();
        break;
    }
    delay(100);
}