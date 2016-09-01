#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
}

void loop() {
  int pot = board.potentiometer.read();
  char symbol = map(pot, 0, 1022, 20, 126);
  board.ledmatrix.print(symbol);
}
