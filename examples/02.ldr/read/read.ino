#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = board.ldr.read();
  Serial.println(value);
  delay(100);
}
