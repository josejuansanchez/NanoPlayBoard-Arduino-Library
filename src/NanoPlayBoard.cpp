/*
  NanoPlayBoard.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 15, 2016.
  Released under GNU GPL v3.
*/

#include "Arduino.h"
#include "NanoPlayBoard.h"

NanoPlayBoard::NanoPlayBoard()
{
  potentiometer = Potentiometer(PIN_POT);
  ldr           = LDR(PIN_LDR);
  ledmatrix     = LedMatrix(PIN_DATA_IN, PIN_CLOCK_IN, PIN_CLOCK_OUT);
  servo[0]      = NanoServo(PIN_SERVO_1);
  servo[1]      = NanoServo(PIN_SERVO_2);
  servos        = NanoServos(PIN_SERVO_1, PIN_SERVO_2);
  buttons.top   = Button(PIN_HC148_A0, PIN_HC148_A1, TOP);
  buttons.down  = Button(PIN_HC148_A0, PIN_HC148_A1, DOWN);
  buttons.left  = Button(PIN_HC148_A0, PIN_HC148_A1, LEFT);
  buttons.right = Button(PIN_HC148_A0, PIN_HC148_A1, RIGHT);
  rotaryencoder = RotaryEncoder(PIN_ROTARY_ENCODER_A, PIN_ROTARY_ENCODER_B);
}
