/*
  RotaryEncoder.h - Library for the Arduino NanoPlayBoard
  Created by José Juan Sánchez, September 21, 2016.
  Released under GNU GPL v3.
*/

#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include "Arduino.h"

class RotaryEncoder
{
  public:
    RotaryEncoder();
    RotaryEncoder(uint8_t pin_a, uint8_t pin_b);
    long getPosition();

  protected:
    static void handleInterrupt();

  private:
    uint8_t _pin_a;
    static uint8_t _pin_b;
    static long _position;
};

#endif