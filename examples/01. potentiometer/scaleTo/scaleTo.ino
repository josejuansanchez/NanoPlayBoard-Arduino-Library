#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  int potValue = board.potentiometer.scaleTo(0, 99);
  board.ledmatrix.printInLandscape(potValue);
}
