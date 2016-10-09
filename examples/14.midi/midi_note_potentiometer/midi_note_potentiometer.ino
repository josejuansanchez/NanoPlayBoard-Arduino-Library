#include <NanoPlayBoard.h>
#include "MIDINoteNumbers.h"

NanoPlayBoard board;

int samplingInterval = 19;
unsigned long currentMillis;
unsigned long previousMillis;

int pitch;
int previousPitch;

void setup() {
  Serial.begin(115200);
}

void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

void loop() {
  currentMillis = millis();
  if (currentMillis - previousMillis > samplingInterval) {
    previousMillis += samplingInterval;

    pitch = board.potentiometer.scaleTo(0, 127);

    if (pitch == previousPitch) return;

    noteOn(0x90, previousPitch, 0x00);
    noteOn(0x90, pitch, 0x6E);
    previousPitch = pitch;
  }
  
  board.ledmatrix.print(midi_note_numbers[pitch]);
}
