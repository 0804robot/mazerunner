#ifndef CORNER_H
#define CORNER_H

class CornerMerchantry
{
private:
    /* data */
public:
    CornerMerchantry(/* args */);
    ~CornerMerchantry();
    void attachPins(int trigPin, int echoPin);
    float getDistance_front();
    float getDistance_side();

};


#endif