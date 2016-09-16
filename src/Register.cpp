/*
  Register.h - Library for the Arduino Nano PlayBoard
  Created by Antonio Morales, June, 2016.
  Released into the public domain.
*/

#include <Arduino.h>
#include "Register.h"

Register::Register()
{
    _dIn = 13;
    _clkIn = 12;
    _clkOut = 6;
    _baudRate = 9600;
    _period = long(1000000/_baudRate);
    
    pinMode(_dIn, OUTPUT);
    pinMode(_clkIn, OUTPUT);
    pinMode(_clkOut, OUTPUT);
    digitalWrite(_dIn, LOW);
    digitalWrite(_clkIn, LOW);
    digitalWrite(_clkOut, LOW);

    clear();
}

void Register::clear()
{
    write(0);
}

void Register::write(byte data)
{
    digitalWrite(_clkIn, LOW);
    digitalWrite(_clkOut, LOW);

    for(uint8_t k = 0; k < 8; k++) {
        delayMicroseconds(long(_period/4));
        digitalWrite(_dIn,bitRead(data,k));
        delayMicroseconds(long(_period/4));
        digitalWrite(_clkIn,HIGH);
        delayMicroseconds(long(_period/2));
        digitalWrite(_clkIn, LOW);
    }
    delayMicroseconds(int(_period/4));
    digitalWrite(_clkOut, HIGH);
    delayMicroseconds(long(_period/2));
    digitalWrite(_clkOut, LOW);
}
