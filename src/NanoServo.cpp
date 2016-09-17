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

void NanoServo::write(uint8_t value)
{
    if (!servo.attached()) {
        servo.attach(_pin);
    }
    servo.write(value);
}
