#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
  
}

void loop() {
  board.rgb.setColor("FF0000");
    
  for(int i = 100; i > 0; i--) {
    board.rgb.setIntensity(i);
    delay(10);
  }
}
