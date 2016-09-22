/*
  NanoPlayBoard.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 15, 2016.
  Released under GNU GPL v3.
*/

#ifndef NanoPlayBoard_h
#define NanoPlayBoard_h

#include "NanoPlayBoardA.h"
#include "PinsModelB.h"
#include "LedMatrix.h"
#include "NanoServo.h"
#include "NanoServos.h"
#include "Button.h"
#include "RotaryEncoder.h"
#include "Bluetooth.h"

#include "ThirdParty-NewPing.h"


class NanoPlayBoard: public NanoPlayBoardA
{
  public:
    NanoPlayBoard();
    LedMatrix ledmatrix;
    NanoServo servo[2];
    NanoServos servos;
    RotaryEncoder rotaryencoder;
    Bluetooth bluetooth;
    NewPing ultrasound;

    struct {
      Button top;
      Button down;
      Button left;
      Button right;
    } buttons;


};

#endif
