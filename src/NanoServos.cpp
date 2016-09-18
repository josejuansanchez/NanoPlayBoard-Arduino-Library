/*
  NanoServos.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 17, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "NanoServos.h"

NanoServos::NanoServos() {}

NanoServos::NanoServos(uint8_t pin_right, uint8_t pin_left)
{
    _servo_right = NanoServo(pin_right);
    _servo_left = NanoServo(pin_left);
}

void NanoServos::forward()
{
    _servo_right.to(RIGHT_FORWARD);
    _servo_left.to(LEFT_FORWARD);
}

void NanoServos::backward()
{
    _servo_right.to(RIGHT_BACKWARD);
    _servo_left.to(LEFT_BACKWARD);
}

void NanoServos::right()
{
    _servo_right.to(STOP);
    _servo_left.to(LEFT_FORWARD);
}

void NanoServos::left()
{
    _servo_right.to(RIGHT_FORWARD);
    _servo_left.to(STOP);
}

void NanoServos::stop()
{
    _servo_right.to(STOP);
    _servo_left.to(STOP);
}