/*
  LedMatrix.cpp - Library for the Arduino NanoPlayBoard
  Created by Antonio Morales and José Juan Sánchez, September, 2016.
  Released under GNU GPL v3.
*/

#include "Arduino.h"
#include "LedMatrix.h"

#ifdef BOARD_MODEL_B
  uint8_t LedMatrix::_column_values[5] = {128, 64, 32, 16, 8};
#else
  uint8_t LedMatrix::_column_pins[5] = PIN_LEDMATRIX_COLUMNS;
#endif

LedMatrix::LedMatrix() {}

LedMatrix::LedMatrix(uint8_t data_in, uint8_t clock_in, uint8_t clock_out)
{
  _register = Register(data_in, clock_in, clock_out);
  _register.clear();
  _scroll_speed = 10;

  #ifndef BOARD_MODEL_B
    for(uint8_t i = 0; i < 5; i++) {
      pinMode(_column_pins[i], OUTPUT);
      digitalWrite(_column_pins[i], LOW);
    }
  #endif
}

void LedMatrix::print(char symbol)
{
  if (isPrintable(symbol)) {
    for(uint8_t i = 0; i < 5; i++) {

      #ifdef BOARD_MODEL_B
        _register.write(_column_values[i]);
        _register.write(pgm_read_byte(&ascii[symbol-0x20][i]));
        _register.write(0);
      #else
        _register.write(pgm_read_byte(&ascii[symbol-0x20][i]));
        digitalWrite(_column_pins[i], HIGH);
        delay(2);
        digitalWrite(_column_pins[i], LOW);
      #endif

    }
  } else {
    print(' ');
  }
}

void LedMatrix::print(const byte pattern[5])
{
  for(uint8_t i = 0; i < 5; i++) {

    #ifdef BOARD_MODEL_B
      _register.write(_column_values[i]);
      _register.write(pattern[i]);
      _register.write(0);
    #else
      _register.write(pattern[i]);
      digitalWrite(_column_pins[i], HIGH);
      delay(2);
      digitalWrite(_column_pins[i], LOW);
    #endif

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
    for(uint8_t n = 0; n < _scroll_speed; n++) {
      print(pattern);
    }
  }
}

void LedMatrix::print(String message)
{
  char msg_char[256];
  message.toCharArray(msg_char, 256);
  print(msg_char);
}

void LedMatrix::setScrollSpeed(uint8_t speed)
{
  _scroll_speed = speed;
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

bool LedMatrix::isPrintable(char symbol)
{
  return ((symbol >= 0x20) && (symbol <=0x7e));
}
