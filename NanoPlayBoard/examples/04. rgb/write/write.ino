#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  board.rgb.write(255, 0, 0);  
  delay(500);
  board.rgb.write(0, 255, 0);
  delay(500);
  board.rgb.write(0, 0, 255);  
  delay(500);
}
