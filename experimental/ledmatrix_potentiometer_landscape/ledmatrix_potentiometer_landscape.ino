#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
    
}

void loop() {
  int potValue = board.potentiometer.read();
  int number = map(potValue, 0, 1022, 0, 99);
  board.ledmatrix.printInLandscape(number);
}
