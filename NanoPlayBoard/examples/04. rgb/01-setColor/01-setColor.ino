#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  board.rgb.setColor(255, 0, 0);  
  delay(500);
  board.rgb.setColor(0, 255, 0);
  delay(500);
  board.rgb.setColor(0, 0, 255);  
  delay(500);
}
