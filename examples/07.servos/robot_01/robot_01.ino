#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  board.servos.goForward(1000);
  board.servos.goBackward(1000);
  board.servos.goRight(1000);
  board.servos.goLeft(1000);
}
