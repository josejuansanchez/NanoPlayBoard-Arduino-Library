/*
  RGB.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "RGB.h"

RGB::RGB()
{
  _pinR = 9;
  _pinG = 10;
  _pinB = 11;    
  
  pinMode(_pinR, OUTPUT);
  pinMode(_pinG, OUTPUT);
  pinMode(_pinB, OUTPUT);  
}

void RGB::write(int r, int g, int b)
{
  analogWrite(_pinR, r);
  analogWrite(_pinG, g);
  analogWrite(_pinB, b);
}