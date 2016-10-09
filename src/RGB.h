/*
  RGB.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released under GNU GPL v3.
*/

#ifndef RGB_h
#define RGB_h

#include "Arduino.h"

class RGB
{
  public:
    RGB();
    RGB(uint8_t pin_r, uint8_t pin_g, uint8_t pin_b);
    void setColor(uint8_t r, uint8_t g, uint8_t b);
    void setColor(String color);
    void setIntensity(uint8_t intensity);
    void on();
    void off();
    void toggle();

  protected:
    void write(uint8_t r, uint8_t g, uint8_t b);

  private:
    uint8_t _pin_r;
    uint8_t _pin_g;
    uint8_t _pin_b;
    uint8_t _r;
    uint8_t _g;
    uint8_t _b;
    bool _is_on;
};

#endif
