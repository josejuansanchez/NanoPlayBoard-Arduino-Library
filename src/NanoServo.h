/*
  NanoServo.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 17, 2016.
  Released into the public domain.
*/

#ifndef NanoServo_h
#define NanoServo_h

#include "Arduino.h"
#include "NanoServo.h"
#include <Servo.h>

class NanoServo
{
  public:
    NanoServo();
    NanoServo(uint8_t pin);
    void write(uint8_t value);

  private:
    uint8_t _pin;
    Servo servo;
};

#endif
