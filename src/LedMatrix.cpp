/*
  LedMatrix.cpp - Library for the Arduino Nano PlayBoard
  Created by Antonio Morales and José Juan Sánchez, September, 2016.
  Released into the public domain.
*/

#include "Arduino.h"
#include "LedMatrix.h"

uint8_t LedMatrix::_columnValues[5] = PIN_LEDMATRIX_VALUES;

LedMatrix::LedMatrix() {}

LedMatrix::LedMatrix(uint8_t dIn, uint8_t clkIn, uint8_t clkOut)
{
  _register = Register(dIn, clkIn, clkOut);
  _register.clear();
  _scrollSpeed = 10;
}

void LedMatrix::print(char symbol)
{
  if ((symbol >= 0x20) & (symbol <=0x7e)) {
    for(uint8_t i = 0; i < 5; i++) {
      _register.write(_columnValues[i]);
      _register.write(pgm_read_byte(&ascii[symbol-0x20][i]));
      _register.write(0);
    }
  } else {
    for(uint8_t i = 0; i < 5; i++) {
      _register.write(_columnValues[i]);
      _register.write(pgm_read_byte(&ascii[0][i]));
      _register.write(0);
    }
  }
}

void LedMatrix::print(const byte pattern[5])
{
  for(uint8_t i = 0; i < 5; i++) {
    _register.write(_columnValues[i]);
    _register.write(pattern[i]);
    _register.write(0);
  }
}

void LedMatrix::print(char message[])
{
  byte pattern[5];
  for (uint8_t i = 0; i < (strlen(message)*5-4); i++) {
    pattern[0] = pgm_read_byte(&ascii[message[i/5]-0x20][i%5]);
    pattern[1] = pgm_read_byte(&ascii[message[(i+1)/5]-0x20][(i+1)%5]);
    pattern[2] = pgm_read_byte(&ascii[message[(i+2)/5]-0x20][(i+2)%5]);
    pattern[3] = pgm_read_byte(&ascii[message[(i+3)/5]-0x20][(i+3)%5]);
    pattern[4] = pgm_read_byte(&ascii[message[(i+4)/5]-0x20][(i+4)%5]);

    // Display the pattern several times
    for(uint8_t n = 0; n < _scrollSpeed; n++) {
      print(pattern);
    }
  }
}

void LedMatrix::print(String message)
{
  char msgChar[256];
  message.toCharArray(msgChar, 256);
  print(msgChar);
}

void LedMatrix::setScrollSpeed(uint8_t speed)
{
  _scrollSpeed = speed;
}

void LedMatrix::clear()
{
  print(' ');
}

void LedMatrix::printInLandscape(uint8_t number)
{
  byte pattern[5];
  for(uint8_t i = 0; i < 5; i++) {
    pattern[i] = pgm_read_byte(&landscape_numbers[number][i]);
  }
  print(pattern);
}
