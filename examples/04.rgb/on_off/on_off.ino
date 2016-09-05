#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
  
}

void loop() {
  board.rgb.on();
  delay(1000);
  board.rgb.off();
  delay(1000);
}
