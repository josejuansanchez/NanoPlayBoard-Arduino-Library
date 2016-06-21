#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  byte pattern[5] = {
    0b00010000,
    0b01001000,
    0b00001000,
    0b01001000,
    0b00010000
    };

  board.ledmatrix.print(pattern);  
}
