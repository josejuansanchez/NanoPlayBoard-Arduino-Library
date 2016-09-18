/*
  NanoPlayBoardA.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, June 19, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "NanoPlayBoardA.h"

NanoPlayBoardA::NanoPlayBoardA()
{
    potentiometer = Potentiometer(PIN_POT);
    ldr           = LDR(PIN_LDR);
    buzzer        = Buzzer(PIN_BUZZER);
    rgb           = RGB(PIN_R, PIN_G, PIN_B);
    ledmatrix     = LedMatrixA(PIN_DATA_IN, PIN_CLOCK_IN, PIN_CLOCK_OUT);
}
