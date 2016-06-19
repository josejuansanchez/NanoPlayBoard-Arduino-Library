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
  pinMode(_pin, OUTPUT);
}

LDR::LDR(int pin)
{
  _pin = pin;
  pinMode(pin, OUTPUT);
}

int LDR::read()
{
  return analogRead(_pin);
}