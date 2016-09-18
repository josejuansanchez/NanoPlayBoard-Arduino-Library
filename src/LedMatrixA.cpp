/*
  LedMatrixA.cpp - Library for the Arduino Nano PlayBoard
  Created by Antonio Morales, June, 2016.
  Contributions by José Juan Sánchez.
  Released into the public domain.
*/

#include "Arduino.h"
#include "LedMatrixA.h"

uint8_t LedMatrixA::_columnPins[5] = PIN_LEDMATRIX_COLUMNS;

LedMatrixA::LedMatrixA() {}

LedMatrixA::LedMatrixA(uint8_t dIn, uint8_t clkIn, uint8_t clkOut)
{
  // Initialize the pins used for the columns as outputs
  for(uint8_t i = 0; i < 5; i++) {
    pinMode(_columnPins[i], OUTPUT);
    digitalWrite(_columnPins[i], LOW);
  }
  
  // Initialize and clear the shift register
  _register = Register(dIn, clkIn, clkOut);
  _register.clear();

  // Initialize the text scroll speed used to display messages
  _scrollSpeed = 10;
}

// Display the symbol passed as argument.
// A checking is needed to validate if the argument is inside the valid range.
// If the argument is outside the range then a white space is displayed.
//*************************************************************
void LedMatrixA::print(char symbol)
{
  if ((symbol >= 0x20) & (symbol <=0x7e)) {
    for(uint8_t i = 0; i < 5; i++) {
      _register.write(pgm_read_byte(&ascii[symbol-0x20][i]));
      digitalWrite(_columnPins[i], HIGH);
      delay(2);
      digitalWrite(_columnPins[i], LOW);
    }
  } else {
    for(uint8_t i = 0; i < 5; i++) {
      _register.write(pgm_read_byte(&ascii[0][i]));
      digitalWrite(_columnPins[i], HIGH);
      delay(2);
      digitalWrite(_columnPins[i], LOW);
    }
  }
}

// Display the pattern stored in the array of bytes
void LedMatrixA::print(const byte pattern[5])
{
  for(uint8_t i = 0; i < 5; i++) {
    _register.write(pattern[i]);
    digitalWrite(_columnPins[i], HIGH);
    delay(2);
    digitalWrite(_columnPins[i], LOW);
  }
}

// Display the message stored in the array of chars
void LedMatrixA::print(char message[])
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

// Display the message stored in the String object
void LedMatrixA::print(String message)
{
  char msgChar[256];
  message.toCharArray(msgChar, 256);
  print(msgChar);
}

void LedMatrixA::setScrollSpeed(uint8_t speed)
{
  _scrollSpeed = speed;
}

void LedMatrixA::clear()
{
  print(' ');
}

void LedMatrixA::printInLandscape(uint8_t number)
{
  byte pattern[5];
  for(uint8_t i = 0; i < 5; i++) {
    pattern[i] = pgm_read_byte(&landscape_numbers[number][i]);
  }
  print(pattern);
}
