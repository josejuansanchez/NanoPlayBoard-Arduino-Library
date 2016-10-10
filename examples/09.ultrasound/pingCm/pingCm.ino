#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
  board.bluetooth.begin(9600);
}

void loop() {
  int distance = board.ultrasound.pingCm();
  board.ledmatrix.printInLandscape(distance);
  board.bluetooth.println(distance);
  delay(10);
}
