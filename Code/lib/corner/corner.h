#ifndef CORNER_H
#define CORNER_H

typedef enum{
  LEFT,
  RIGHT,
  FORWARD,
  BRAKE,
}turn_direction;


class CornerMerchantry
{
private:
    bool wall_detected(float, float);
    float *set_threshold_right;
    float *set_threshold_front;
public:
    CornerMerchantry(float*, float*);
    ~CornerMerchantry();
    void attachPins(int trigPin, int echoPin);
    float getDistance_front();
    float getDistance_side();
    turn_direction getTurnDirection();
};


#endif