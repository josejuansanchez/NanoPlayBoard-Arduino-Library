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
    void setColor(uint8_t r, uint8_t g, uint8_t b);
    void setColor(String color);

  protected:
    void write(uint8_t r, uint8_t g, uint8_t b);

  private:
    uint8_t _pinR;
    uint8_t _pinG;
    uint8_t _pinB;
    uint8_t _r;
    uint8_t _g;
    uint8_t _b;
};

#endif
