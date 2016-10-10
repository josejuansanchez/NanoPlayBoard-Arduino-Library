#include <NanoPlayBoard.h>

#define MAX_DISTANCE_FROM_OBSTACLE 10

NanoPlayBoard board;

void setup() {

}

void loop() {
  int distance = board.ultrasound.pingCm();
  board.ledmatrix.printInLandscape(distance);

  if (distance < MAX_DISTANCE_FROM_OBSTACLE && distance !=0) {
    board.servos.stop();
    //board.servos.goBackward(1000);
    //board.servos.goRight(1000);
  } else {
    board.servos.goForward();
  }
}
