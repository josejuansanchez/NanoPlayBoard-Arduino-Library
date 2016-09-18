/*
  NanoSerial.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 16, 2016.
  Released into the public domain.
*/

#ifndef NanoSerial_h
#define NanoSerial_h

#include "Arduino.h"

class NanoSerial
{
  public:
    NanoSerial();
    NanoSerial(uint8_t pin);

  private:
    uint8_t _pin;
};

#endif