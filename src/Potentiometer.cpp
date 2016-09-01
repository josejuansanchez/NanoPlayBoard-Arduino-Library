/*
  Potentiometer.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Potentiometer.h"

Potentiometer::Potentiometer()
{
  _pin = A1;
}

int Potentiometer::read()
{
  return analogRead(_pin);
}
