/*
  Button.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 19, 2016.
  Released under GNU GPL v3.
*/

#ifndef Button_h
#define Button_h

#include "Arduino.h"

enum button_t {BUTTON_TOP, BUTTON_DOWN, BUTTON_LEFT, BUTTON_RIGHT};

class Button
{
  public:
    Button();
    Button(uint8_t pin_a0, uint8_t pin_a1, button_t type);
    bool isPressed();

  protected:
    button_t whatButtonIsPressed();

  private:
    uint8_t _pin_a0;
    uint8_t _pin_a1;
    button_t _type;
};

#endif
