/*
  NanoPlayBoard.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 15, 2016.
  Released into the public domain.
*/

#ifndef NanoPlayBoard_h
#define NanoPlayBoard_h

#include "NanoPlayBoardA.h"
#include "PinsModelB.h"
#include "LedMatrix.h"
#include "NanoServo.h"
#include "NanoServos.h"

class NanoPlayBoard: public NanoPlayBoardA
{
  public:
    NanoPlayBoard();
    LedMatrix ledmatrix;
    NanoServo servo[2];
    NanoServos servos;
};

#endif
