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

  _r = 255;
  _g = 255;
  _b = 255;
}

void RGB::write(uint8_t r, uint8_t g, uint8_t b)
{
  analogWrite(_pinR, r);
  analogWrite(_pinG, g);
  analogWrite(_pinB, b);
}

void RGB::setColor(uint8_t r, uint8_t g, uint8_t b)
{
  _r = r;
  _g = g;
  _b = b;

  write(_r, _g, _b);
}

void RGB::setColor(String hexColor)
{
  if (hexColor.startsWith("#")) {
    hexColor = hexColor.substring(1);
  }

  long longColor = (long) strtol(&hexColor[0], NULL, 16);
  _r = longColor >> 16;
  _g = longColor >> 8 & 0xFF;
  _b = longColor & 0xFF;

  write(_r, _g, _b);
}

void RGB::setIntensity(int intensity)
{
  float scale = intensity / 100.0;
  write((int)_r * scale, (int)_g * scale, (int)_b * scale);
}

void RGB::on()
{
  write(_r, _g, _b);
}

void RGB::off()
{
  write(0, 0, 0);
}
