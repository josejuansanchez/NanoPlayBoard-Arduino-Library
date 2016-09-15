/*
  Potentiometer.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Potentiometer.h"

Potentiometer::Potentiometer()
{

}

Potentiometer::Potentiometer(uint8_t pin)
{
  _pin = pin;
}

int Potentiometer::read()
{
  return analogRead(_pin);
}

int Potentiometer::scaleTo(int toLow, int toHigh)
{
    return scaleTo(0, 1022, toLow, toHigh);
}

int Potentiometer::scaleTo(int fromLow, int fromHigh, int toLow, int toHigh)
{
    int value = read();
    return map(value, fromLow, fromHigh, toLow, toHigh);
}