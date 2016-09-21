/*
  RotaryEncoder.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 21, 2016.
  Released under GNU GPL v3.

  Reference: http://playground.arduino.cc/Main/RotaryEncoders  
*/

#include "Arduino.h"
#include "RotaryEncoder.h"

uint8_t RotaryEncoder::_pin_a;
uint8_t RotaryEncoder::_pin_b;
long RotaryEncoder::_position = 0;

RotaryEncoder::RotaryEncoder() {}

RotaryEncoder::RotaryEncoder(uint8_t pin_a, uint8_t pin_b)
{
  _pin_a = pin_a;
  _pin_b = pin_b;

  attachInterrupt(digitalPinToInterrupt(_pin_a), handleInterrupt, CHANGE);

  pinMode(_pin_a, INPUT);
  pinMode(_pin_b, INPUT);
}

long RotaryEncoder::getPosition()
{
  return _position;
}

static void RotaryEncoder::handleInterrupt()
{
  if (digitalRead(_pin_a) == digitalRead(_pin_b)) {
    _position--;
  } else {
    _position++;
  }
}