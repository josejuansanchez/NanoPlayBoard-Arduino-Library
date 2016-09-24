/*
  NanoPlayBoard.cpp - Library for the Arduino NanoPlayBoard
  Created by José Juan Sánchez, September 15, 2016.
  Released under GNU GPL v3.
*/

#include "Arduino.h"
#include "NanoPlayBoard.h"

#ifdef BOARD_MODEL_B

NanoPlayBoard::NanoPlayBoard():
  bluetooth(PIN_BLUETOOTH_RX, PIN_BLUETOOTH_TX)
{
  potentiometer = Potentiometer(PIN_POT);
  ldr           = LDR(PIN_LDR);
  buzzer        = Buzzer(PIN_BUZZER);
  rgb           = RGB(PIN_R, PIN_G, PIN_B);
  ledmatrix     = LedMatrix(PIN_DATA_IN, PIN_CLOCK_IN, PIN_CLOCK_OUT);
  servo[0]      = NanoServo(PIN_SERVO_1);
  servo[1]      = NanoServo(PIN_SERVO_2);
  servos        = NanoServos(PIN_SERVO_1, PIN_SERVO_2);
  buttons.top   = Button(PIN_HC148_A0, PIN_HC148_A1, BUTTON_TOP);
  buttons.down  = Button(PIN_HC148_A0, PIN_HC148_A1, BUTTON_DOWN);
  buttons.left  = Button(PIN_HC148_A0, PIN_HC148_A1, BUTTON_LEFT);
  buttons.right = Button(PIN_HC148_A0, PIN_HC148_A1, BUTTON_RIGHT);
  rotaryencoder = RotaryEncoder(PIN_ROTARY_ENCODER_A, PIN_ROTARY_ENCODER_B);
  ultrasound    = NewPing(PIN_SONAR_TRIGGER, PIN_SONAR_ECHO);

  bluetooth.begin(9600);
}

#else

NanoPlayBoard::NanoPlayBoard()
{
  potentiometer = Potentiometer(PIN_POT);
  ldr           = LDR(PIN_LDR);
  buzzer        = Buzzer(PIN_BUZZER);
  rgb           = RGB(PIN_R, PIN_G, PIN_B);
  ledmatrix     = LedMatrix(PIN_DATA_IN, PIN_CLOCK_IN, PIN_CLOCK_OUT);
}

#endif
