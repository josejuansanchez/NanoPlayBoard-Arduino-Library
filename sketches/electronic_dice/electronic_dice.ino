#include <NanoPlayBoard.h>

NanoPlayBoard board;

byte pattern[6][5] =
  {{0, 0, 16, 0, 0},
  {64, 0, 0, 0, 4},
  {64, 0, 16, 0, 4},
  {68, 0, 0, 0, 68},
  {68, 0, 16, 0, 68},
  {84, 0, 0, 0, 84}};

void setup() {
}

void loop() {
  int pot = board.potentiometer.read();
  int index = map(pot, 0, 1022, 0, 5);
  board.ledmatrix.print(pattern[index]);
}
