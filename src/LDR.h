/*
  LDR.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released under GNU GPL v3.
*/

#ifndef LDR_h
#define LDR_h

#include "Arduino.h"

class LDR
{
  public:
    LDR();
    LDR(uint8_t pin);
    int read();
    int scaleTo(int to_low, int to_high);
    int scaleTo(int from_low, int from_high, int to_low, int to_high);

  private:
    uint8_t _pin;
};

#endif