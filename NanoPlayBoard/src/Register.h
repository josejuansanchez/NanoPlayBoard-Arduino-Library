/*
  Register.h - Library for the Arduino Nano PlayBoard
  Created by Antonio Morales, June, 2016.
  Released into the public domain.
*/

#ifndef Register_h
#define Register_h

#include <Arduino.h>

class Register
{
    public:
        Register();
        void clear();
        void write(byte data);

    private:
        unsigned int _Din;    // Pin attached to the serial pin in the shift register
        unsigned int _ClkIn;  // Pin attached to the shift clock pin in the shift register
        unsigned int _ClkOut; // Pin atrached to the latch clock pin in the shift register
        unsigned long _period;
        unsigned int _baudRate;
};

#endif