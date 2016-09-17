/*
  NanoPlayBoardB.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 15, 2016.
  Released into the public domain.
*/

#ifndef NanoPlayBoardB_h
#define NanoPlayBoardB_h

#include "NanoPlayBoard.h"
#include "PinsModelB.h"
#include "LedMatrixB.h"
#include "NanoServo.h"

class NanoPlayBoardB: public NanoPlayBoard
{
  public:
    NanoPlayBoardB();
    LedMatrixB ledmatrix;
    NanoServo servo[2];
};

#endif
