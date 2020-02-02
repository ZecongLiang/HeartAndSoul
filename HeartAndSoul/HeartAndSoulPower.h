#ifndef HearAndSoul_h
#define HeartAndSoul

//Standard Arduino libraries
#include <Arduino.h>

class HeartAndSoul
{
  private:

  public:
    bool isCharging();
    uint16_t getBatteryVolt();
  
}; //need the semicolon, terminates the line

#endif
