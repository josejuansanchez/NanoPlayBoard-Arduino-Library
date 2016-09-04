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

int LDR::scaleTo(int toLow, int toHigh)
{
    return scaleTo(0, 1022, 0, 99);
}

int LDR::scaleTo(int fromLow, int fromHigh, int toLow, int toHigh)
{
    int value = read();
    return map(value, fromLow, fromHigh, toLow, toHigh);
}