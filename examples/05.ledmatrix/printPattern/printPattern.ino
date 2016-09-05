#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
}

void loop() {
  /*
  byte pattern[5] = {
    0b00010000,
    0b01001000,
    0b00001000,
    0b01001000,
    0b00010000
    };
  */
  byte pattern[5] = {16, 72, 8, 72, 16};
  board.ledmatrix.print(pattern);  
}
