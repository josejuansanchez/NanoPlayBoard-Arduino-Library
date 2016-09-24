/*
  NanoPlayBoard.h - Library for the Arduino NanoPlayBoard
  Created by José Juan Sánchez, September 15, 2016.
  Released under GNU GPL v3.
*/

#ifndef NanoPlayBoard_h
#define NanoPlayBoard_h

#include "Configuration.h"
#include "Potentiometer.h"
#include "RGB.h"
#include "LDR.h"
#include "Buzzer.h"
#include "LedMatrix.h"
#include "NanoServo.h"
#include "NanoServos.h"
#include "Button.h"
#include "RotaryEncoder.h"
#include "NewPing.h"
#include "MMA7660FC.h"
#include <SoftwareSerial.h>

class NanoPlayBoard
{
  public:
    NanoPlayBoard();
    Potentiometer potentiometer;
    RGB rgb;
    LDR ldr;
    Buzzer buzzer;
    LedMatrix ledmatrix;

  #ifdef BOARD_MODEL_B
    NanoServo servo[2];
    NanoServos servos;
    RotaryEncoder rotaryencoder;
    SoftwareSerial bluetooth;
    NewPing ultrasound;
    MMA7660FC accelerometer;

    struct {
      Button top;
      Button down;
      Button left;
      Button right;
    } buttons;
  #endif
};

#endif
