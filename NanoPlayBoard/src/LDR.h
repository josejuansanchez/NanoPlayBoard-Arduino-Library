/*
  LDR.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/
#ifndef LDR_h
#define LDR_h

#include "Arduino.h"

class LDR
{
  public:
    LDR();
    int read();

  private:
    int _pin;
};

#endif