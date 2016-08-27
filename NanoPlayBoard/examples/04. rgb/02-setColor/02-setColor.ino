#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
  
}

void loop() {
  board.rgb.setColor("#FF0000");
  delay(1000);
  board.rgb.setColor("#00FF00");
  delay(1000);
  board.rgb.setColor("#0000FF");
  delay(1000);
}
