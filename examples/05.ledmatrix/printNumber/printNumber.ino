#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  int number = board.potentiometer.scaleTo(0, 99);
  board.ledmatrix.printNumber(number);
}
