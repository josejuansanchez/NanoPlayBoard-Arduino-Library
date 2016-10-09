/*
  Buzzer.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released under GNU GPL v3.
*/

#include "Arduino.h"
#include "Buzzer.h"

Buzzer::Buzzer() {}

Buzzer::Buzzer(uint8_t pin)
{
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void Buzzer::playTone(unsigned int frequency)
{
  tone(_pin, frequency);
}

void Buzzer::playTone(unsigned int frequency, unsigned long duration)
{
  tone(_pin, frequency, duration);
}

void Buzzer::stopTone()
{
  noTone(_pin);
}