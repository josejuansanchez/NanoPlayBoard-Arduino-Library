/*
  NanoPlayBoardA.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/

#ifndef NanoPlayBoardA_h
#define NanoPlayBoardA_h

#include "Arduino.h"
#include "Potentiometer.h"
#include "RGB.h"  
#include "LDR.h"
#include "Buzzer.h"
#include "LedMatrixA.h"
#include "PinsModelA.h"

class NanoPlayBoardA
{
  public:
    NanoPlayBoardA();
    Potentiometer potentiometer;
    RGB rgb;
    LDR ldr;
    Buzzer buzzer;
    LedMatrixA ledmatrix;
};

#endif
