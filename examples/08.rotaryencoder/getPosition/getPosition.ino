#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
  board.bluetooth.begin(9600);
}

void loop() {
  long position = board.rotaryencoder.getPosition();
  board.bluetooth.println(position);
  delay(50);
}
