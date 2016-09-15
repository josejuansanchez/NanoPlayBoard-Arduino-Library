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

NanoPlayBoard::NanoPlayBoard(uint8_t type)
{
    uint8_t pot_pin;

    switch(type) {
        case MODEL_A:
        pot_pin = A1;
        break;

        case MODEL_B:
        pot_pin = A7;
        break;
    }

    potentiometer = Potentiometer(pot_pin);
}
