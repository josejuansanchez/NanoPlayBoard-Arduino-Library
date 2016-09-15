/*
  NanoPlayBoard.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "NanoPlayBoard.h"

NanoPlayBoard::NanoPlayBoard()
{
    NanoPlayBoard(MODEL_A);
}

NanoPlayBoard::NanoPlayBoard(uint8_t model)
{
    #if (NPB_MODEL_A == model)
        #include "PinsModelA.h"
    #else
        #include "PinsModelB.h"
    #endif

    potentiometer = Potentiometer(POT_PIN);
}
