#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  int ldrValue = board.ldr.scaleTo(0, 99);
  board.ledmatrix.printNumber(ldrValue);
}
