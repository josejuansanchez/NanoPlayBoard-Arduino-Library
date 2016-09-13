/*
  LedMatrix.h - Library for the Arduino Nano PlayBoard
  Created by Antonio Morales, June, 2016.
  Contributions by José Juan Sánchez.
  Released into the public domain.
*/

#ifndef LedMatrix_h
#define LedMatrix_h

#include <Arduino.h>
#include "Register.h"
#include "Alphabet.h"
#include "LandscapeNumbers.h"

class LedMatrix
{
    public:
        LedMatrix();
        void clear();
        void print(char symbol);
        void print(const byte pattern[5]);
        void print(char message[]);
        void print(String message);
        void setScrollSpeed(uint8_t speed);
        void printInLandscape(uint8_t number);

    private:
        static uint8_t _columns[5];       // Pins attached to the columns of the led matrix
        Register _register = Register();  // Value that will be written in the shift register for each column
        uint8_t _scrollSpeed;             // Scroll speed used to display messages
};

#endif
