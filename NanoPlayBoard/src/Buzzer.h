/*
  Buzzer.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/
#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

class Buzzer
{
  public:
    Buzzer();
    void playTone(unsigned int frequency);

  private:
    uint8_t _pin;
};

#endif