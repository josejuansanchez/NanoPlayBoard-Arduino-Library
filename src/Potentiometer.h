/*
  Potentiometer.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released under GNU GPL v3.
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
    int scaleTo(int to_low, int to_high);
    int scaleTo(int from_low, int from_high, int to_low, int to_high);

  private:
    uint8_t _pin;
};

#endif
