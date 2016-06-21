#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  int val = board.potentiometer.read();
  board.buzzer.playTone(val);
  delay(100); 
}
