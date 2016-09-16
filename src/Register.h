/*
  Register.h - Library for the Arduino Nano PlayBoard
  Created by Antonio Morales, June, 2016.
  Released into the public domain.
*/

#ifndef Register_h
#define Register_h

#include "Arduino.h"

class Register
{
    public:
        Register();
        Register(uint8_t dIn, uint8_t clkIn, uint8_t clkOut);
        void clear();
        void write(byte data);

    private:
        uint8_t _dIn;             // Pin attached to the serial pin
        uint8_t _clkIn;           // Pin attached to the shift clock
        uint8_t _clkOut;          // Pin atrached to the latch clock
        unsigned long _period;
        unsigned int _baudRate;
};

#endif
