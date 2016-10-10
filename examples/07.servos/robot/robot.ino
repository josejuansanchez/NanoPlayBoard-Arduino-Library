#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  board.servos.goForward();
  delay(1000);
  board.servos.goBackward();
  delay(1000);
  board.servos.goRight();
  delay(1000);
  board.servos.goLeft();
  delay(1000);
}
