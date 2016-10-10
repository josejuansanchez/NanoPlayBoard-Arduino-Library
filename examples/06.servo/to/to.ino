#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  int value = board.potentiometer.scaleTo(0, 180);
  board.ledmatrix.printInLandscape(value);
  board.servo[1].to(value);
}
