/*
  RGB.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "RGB.h"

RGB::RGB() {}

RGB::RGB(uint8_t pin_r, uint8_t pin_g, uint8_t pin_b)
{
  _pin_r = pin_r;
  _pin_g = pin_g;
  _pin_b = pin_b;
  
  pinMode(_pin_r, OUTPUT);
  pinMode(_pin_g, OUTPUT);
  pinMode(_pin_b, OUTPUT);

  _r = 255;
  _g = 255;
  _b = 255;

  _is_on = false;
}

void RGB::write(uint8_t r, uint8_t g, uint8_t b)
{
  analogWrite(_pin_r, r);
  analogWrite(_pin_g, g);
  analogWrite(_pin_b, b);
}

void RGB::setColor(uint8_t r, uint8_t g, uint8_t b)
{
  _r = r;
  _g = g;
  _b = b;

  write(_r, _g, _b);
}

void RGB::setColor(String hex_color)
{
  if (hex_color.startsWith("#")) {
    hex_color = hex_color.substring(1);
  }

  long long_color = (long) strtol(&hex_color[0], NULL, 16);
  _r = long_color >> 16;
  _g = long_color >> 8 & 0xFF;
  _b = long_color & 0xFF;

  write(_r, _g, _b);
}

void RGB::setIntensity(uint8_t intensity)
{
  float scale = intensity / 100.0;
  write((uint8_t)_r * scale, (uint8_t)_g * scale, (uint8_t)_b * scale);
}

void RGB::on()
{
  write(_r, _g, _b);
  _is_on = true;
}

void RGB::off()
{
  write(0, 0, 0);
  _is_on = false;
}

void RGB::toggle()
{
  if (_is_on) {
    off();
  } else {
    on();
  }
}
