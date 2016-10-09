/*
  NanoServo.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 17, 2016.
  Released under GNU GPL v3.
*/

#ifndef NanoServo_h
#define NanoServo_h

#include "Arduino.h"
#include <Servo.h>

class NanoServo
{
  public:
    NanoServo();
    NanoServo(uint8_t pin);
    void to(uint8_t degrees);

  private:
    uint8_t _pin;
    Servo servo;
};

#endif
