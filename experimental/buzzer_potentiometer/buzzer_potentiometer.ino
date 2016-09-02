#include <NanoPlayBoard.h>

#define NOTE_B0  31
#define NOTE_DS8 4978

NanoPlayBoard board;

void setup() {

}

void loop() {
  int potValue = board.potentiometer.read();
  int note = map(potValue, 0, 1023, NOTE_B0, NOTE_DS8);
  board.buzzer.playTone(note, 10);
}
