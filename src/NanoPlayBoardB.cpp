/*
  NanoPlayBoardB.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 15, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "NanoPlayBoardB.h"

NanoPlayBoardB::NanoPlayBoardB()
{
    potentiometer = Potentiometer(PIN_POT);
    ldr           = LDR(PIN_LDR);
    ledmatrix     = LedMatrixB(PIN_DIN, PIN_CLKIN, PIN_CLKOUT);
    servo_right   = NanoServo(PIN_SERVO_RIGHT);
    servo_left    = NanoServo(PIN_SERVO_LEFT);
}
