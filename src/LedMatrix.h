/*
  LedMatrixB.h - Library for the Arduino Nano PlayBoard
  Created by Antonio Morales and José Juan Sánchez, September, 2016.
  Released into the public domain.
*/

#ifndef LedMatrixB_h
#define LedMatrixB_h

#include "Arduino.h"
#include "Register.h"
#include "Alphabet.h"
#include "LandscapeNumbers.h"

class LedMatrixB
{
  public:
    LedMatrixB();
    LedMatrixB(uint8_t dIn, uint8_t clkIn, uint8_t clkOut);
    void clear();
    void print(char symbol);
    void print(const byte pattern[5]);
    void print(char message[]);
    void print(String message);
    void setScrollSpeed(uint8_t speed);
    void printInLandscape(uint8_t number);

  private:
    static uint8_t _columnValues[5];
    Register _register;
    uint8_t _scrollSpeed;
};

#endif
