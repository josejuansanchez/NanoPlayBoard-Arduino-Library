/*
  Button.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 19, 2016.
  Released under GNU GPL v3.
*/

#include "Arduino.h"
#include "Button.h"

Button::Button() {}

Button::Button(uint8_t pin_a0, uint8_t pin_a1, button_type type)
{
  _pin_a0 = pin_a0;
  _pin_a1 = pin_a1;
  _type = type;
}

// TODO: Fix a well known issue with the state of the top button.
// The current version of NanoPlayBoard has a bug and the state of the
// top button cannot be detected. It will fixed in the next version.

button_type Button::whatButtonIsPressed()
{
  uint8_t state_a0 = digitalRead(_pin_a0);
  uint8_t state_a1 = digitalRead(_pin_a1);

  if (state_a0 == 1) {
    if (state_a1 == 1) {
      return TOP;
    } else {
      return RIGHT;
    }
  } else {
    if (state_a1 == 0) {
      return DOWN;
    } else {
      return LEFT;
    }
  }
}

bool Button::isPressed()
{
  return (whatButtonIsPressed() == _type);
}
