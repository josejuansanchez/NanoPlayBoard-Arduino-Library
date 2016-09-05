#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
  board.rgb.setColor("FF0000");
}

void loop() {
  int potValue = board.potentiometer.read();
  int intensity = map(potValue, 0 ,1023, 0 , 100);
  board.rgb.setIntensity(intensity);
  board.ledmatrix.printInLandscape(intensity);
}
