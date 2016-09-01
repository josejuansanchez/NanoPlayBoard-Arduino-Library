/*
  LDR.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "LDR.h"

LDR::LDR()
{
  _pin = A0;
}

int LDR::read()
{
  return analogRead(_pin);
}
