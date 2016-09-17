/*
  NanoServo.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 17, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "NanoServo.h"

NanoServo::NanoServo() {}

NanoServo::NanoServo(uint8_t pin)
{
    _pin = pin;
}

void NanoServo::to(uint8_t degrees)
{
    if (!servo.attached()) {
        servo.attach(_pin);
    }
    servo.write(degrees);
}
