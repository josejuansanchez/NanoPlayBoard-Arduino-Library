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
  setSpeed(100);
}

void NanoServos::goForward(uint32_t milliseconds)
{
  _servo_right.to(_right_forward);
  _servo_left.to(_left_forward);
  delay(milliseconds);  
}

void NanoServos::goBackward(uint32_t milliseconds)
{
  _servo_right.to(_right_backward);
  _servo_left.to(_left_backward);
  delay(milliseconds);  
}

void NanoServos::goRight(uint32_t milliseconds)
{
  _servo_right.to(STOP);
  _servo_left.to(_left_forward);
  delay(milliseconds);
}

void NanoServos::goLeft(uint32_t milliseconds)
{
  _servo_right.to(_right_forward);
  _servo_left.to(STOP);
  delay(milliseconds);  
}

void NanoServos::goForward()
{
  goForward(0);
}

void NanoServos::goBackward()
{
  goBackward(0);
}

void NanoServos::goRight()
{
  goRight(0);
}

void NanoServos::goLeft()
{
  goLeft(0);
}

void NanoServos::stop()
{
  _servo_right.to(STOP);
  _servo_left.to(STOP);
}

void NanoServos::setSpeed(uint8_t speed)
{
  _left_forward = map(speed, 0, 100, STOP, MAX_SPEED_LEFT_FORWARD);
  _left_backward = map(speed, 0, 100, STOP, MAX_SPEED_LEFT_BACKWARD);
  _right_forward = map(speed, 0, 100, STOP, MAX_SPEED_RIGHT_FORWARD);
  _right_backward = map(speed, 0, 100, STOP, MAX_SPEED_RIGHT_BACKWARD);
}