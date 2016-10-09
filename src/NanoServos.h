/*
  NanoServos.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 18, 2016.
  Released under GNU GPL v3.
*/

#ifndef NanoServos_h
#define NanoServos_h

#include "Arduino.h"
#include "NanoServo.h"

#define STOP 90
#define LEFT_FORWARD 0
#define LEFT_BACKWARD 180
#define RIGHT_FORWARD 180
#define RIGHT_BACKWARD 0

class NanoServos
{
  public:
    NanoServos();
    NanoServos(uint8_t pin_right, uint8_t pin_left);
    void goForward();
    void goBackward();
    void goRight();
    void goLeft();
    void stop();

  private:
    NanoServo _servo_right;
    NanoServo _servo_left;
};

#endif
