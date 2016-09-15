/*
  NanoPlayBoard.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/

#ifndef NanoPlayBoard_h
#define NanoPlayBoard_h

#include "Arduino.h"
#include "Potentiometer.h"
#include "RGB.h"  
#include "LDR.h"
#include "Buzzer.h"
#include "LedMatrix.h"

#define MODEL_A 0
#define MODEL_B 1

class NanoPlayBoard
{
  public:
    NanoPlayBoard();
    NanoPlayBoard(uint8_t type);
    Potentiometer potentiometer;
    RGB rgb;
    LDR ldr;
    Buzzer buzzer;
    LedMatrix ledmatrix;
};

#endif