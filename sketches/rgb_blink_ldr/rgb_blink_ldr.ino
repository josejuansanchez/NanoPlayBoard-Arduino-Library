#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
  
}

void loop() {
  int waitTime = board.ldr.read() * 100;
  
  board.rgb.on();
  delay(waitTime);
  board.rgb.off();
  delay(waitTime);
}
