/*
  RGB.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/
#ifndef RGB_h
#define RGB_h

#include "Arduino.h"

class RGB
{
  public:
    RGB();
    void write(int r, int g, int b);

  private:
    int _pinR;
    int _pinG;
    int _pinB;
};

#endif