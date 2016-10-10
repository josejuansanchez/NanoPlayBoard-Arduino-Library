#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
  board.bluetooth.begin(9600);
}

void loop() {
  uint8_t x = board.accelerometer.getX();
  uint8_t y = board.accelerometer.getY();
  uint8_t z = board.accelerometer.getZ();
  board.bluetooth.print("x: ");
  board.bluetooth.println(x);
  board.bluetooth.print("y: ");
  board.bluetooth.println(y);
  board.bluetooth.print("z: ");
  board.bluetooth.println(z);
  delay(100);
}
