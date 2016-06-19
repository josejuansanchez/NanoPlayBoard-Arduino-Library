/*
  Buzzer.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Buzzer.h"

Buzzer::Buzzer()
{
  _pin = 3;
  pinMode(_pin, OUTPUT);
}

Buzzer::Buzzer(int pin)
{
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void Buzzer::playTone(int frequency)
{
  tone(_pin, frequency);
}