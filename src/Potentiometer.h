/*
  Potentiometer.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/

#ifndef Potentiometer_h
#define Potentiometer_h

#include "Arduino.h"

class Potentiometer
{
  public:
    Potentiometer();
    Potentiometer(uint8_t pin);
    int read();
    int scaleTo(int toLow, int toHigh);
    int scaleTo(int fromLow, int fromHigh, int toLow, int toHigh);

  private:
    uint8_t _pin;
};

#endif
