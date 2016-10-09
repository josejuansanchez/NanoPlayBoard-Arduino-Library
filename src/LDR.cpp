/*
  LDR.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released under GNU GPL v3.
*/

#include "Arduino.h"
#include "LDR.h"

LDR::LDR() {}

LDR::LDR(uint8_t pin)
{
  _pin = pin;
}

int LDR::read()
{
  return analogRead(_pin);
}

int LDR::scaleTo(int to_low, int to_high)
{
  return scaleTo(0, 1022, to_low, to_high);
}

int LDR::scaleTo(int from_low, int from_high, int to_low, int to_high)
{
  int value = read();
  return map(value, from_low, from_high, to_low, to_high);
}