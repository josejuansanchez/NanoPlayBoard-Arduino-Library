/*
  Register.h - Library for the Arduino Nano PlayBoard
  Created by Antonio Morales, June, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Register.h"

Register::Register() {}

Register::Register(uint8_t data_in, uint8_t clock_in, uint8_t clock_out)
{
    _data_in = data_in;
    _clock_in = clock_in;
    _clock_out = clock_out;
    _baudrate = 9600;
    _period = long(1000000/_baudrate);

    pinMode(_data_in, OUTPUT);
    pinMode(_clock_in, OUTPUT);
    pinMode(_clock_out, OUTPUT);
    digitalWrite(_data_in, LOW);
    digitalWrite(_clock_in, LOW);
    digitalWrite(_clock_out, LOW);

    clear();
}

void Register::clear()
{
    write(0);
}

void Register::write(byte data)
{
    digitalWrite(_clock_in, LOW);
    digitalWrite(_clock_out, LOW);

    for(uint8_t k = 0; k < 8; k++) {
        delayMicroseconds(long(_period/4));
        digitalWrite(_data_in,bitRead(data,k));
        delayMicroseconds(long(_period/4));
        digitalWrite(_clock_in,HIGH);
        delayMicroseconds(long(_period/2));
        digitalWrite(_clock_in, LOW);
    }

    delayMicroseconds(int(_period/4));
    digitalWrite(_clock_out, HIGH);
    delayMicroseconds(long(_period/2));
    digitalWrite(_clock_out, LOW);
}