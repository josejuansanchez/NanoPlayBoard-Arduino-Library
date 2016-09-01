#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
  
}

void loop() {
  int waitTime = board.potentiometer.read();

  board.rgb.on();
  delay(waitTime);
  board.rgb.off();
  delay(waitTime);
}
