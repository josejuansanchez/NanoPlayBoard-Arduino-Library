/*
  NanoServos.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 17, 2016.
  Released under GNU GPL v3.
*/

#include "Arduino.h"
#include "NanoServos.h"

NanoServos::NanoServos() {}

NanoServos::NanoServos(uint8_t pin_right, uint8_t pin_left)
{
    _servo_right = NanoServo(pin_right);
    _servo_left = NanoServo(pin_left);
}

void NanoServos::goForward()
{
    _servo_right.to(RIGHT_FORWARD);
    _servo_left.to(LEFT_FORWARD);
}

void NanoServos::goBackward()
{
    _servo_right.to(RIGHT_BACKWARD);
    _servo_left.to(LEFT_BACKWARD);
}

void NanoServos::goRight()
{
    _servo_right.to(STOP);
    _servo_left.to(LEFT_FORWARD);
}

void NanoServos::goLeft()
{
    _servo_right.to(RIGHT_FORWARD);
    _servo_left.to(STOP);
}

void NanoServos::stop()
{
    _servo_right.to(STOP);
    _servo_left.to(STOP);
}