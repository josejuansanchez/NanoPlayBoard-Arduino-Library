#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
  board.rgb.setColor("FF0000");
}

void loop() {
  int intensity = board.potentiometer.scaleTo(0, 99);
  board.rgb.setIntensity(intensity);
  board.ledmatrix.printInLandscape(intensity);
}
