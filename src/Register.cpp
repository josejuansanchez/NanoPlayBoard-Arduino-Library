/*
  Register.h - Library for the Arduino Nano PlayBoard
  Created by Antonio Morales, June, 2016.
  Released into the public domain.
*/

#include <Arduino.h>
#include "Register.h"

Register::Register()
{
    _Din = 13;
    _ClkIn = 12;
    _ClkOut = 6;
    _baudRate = 9600;
    _period = long(1000000/_baudRate);
    
    pinMode(_Din, OUTPUT);
    pinMode(_ClkIn, OUTPUT);
    pinMode(_ClkOut, OUTPUT);
    digitalWrite(_Din, LOW);
    digitalWrite(_ClkIn, LOW);
    digitalWrite(_ClkOut, LOW);

    clear();
}

void Register::clear()
{
    write(0);
}

void Register::write(byte data)
{
    digitalWrite(_ClkIn, LOW);
    digitalWrite(_ClkOut, LOW);

    for(uint8_t k = 0; k < 8; k++) {
        delayMicroseconds(long(_period/4));
        digitalWrite(_Din,bitRead(data,k));
        delayMicroseconds(long(_period/4));
        digitalWrite(_ClkIn,HIGH);
        delayMicroseconds(long(_period/2));
        digitalWrite(_ClkIn, LOW);
    }
    delayMicroseconds(int(_period/4));
    digitalWrite(_ClkOut, HIGH);
    delayMicroseconds(long(_period/2));
    digitalWrite(_ClkOut, LOW);
}
