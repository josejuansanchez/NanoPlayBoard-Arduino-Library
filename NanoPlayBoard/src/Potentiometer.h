/*
  Potentiometer.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/
#ifndef Potentiometer_h
#define Potentiometer_h

#include "Arduino.h"

class Potentiometer
{
  public:
    Potentiometer();
    Potentiometer(int pin);
    int read();

  private:
    int _pin;
};

#endif