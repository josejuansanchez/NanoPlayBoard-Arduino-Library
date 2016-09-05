#include <NanoPlayBoard.h>

NanoPlayBoard board;

// timer variables
unsigned long currentMillis;
unsigned long previousMillis;

// how often to run the main loop (in ms)
int samplingInterval = 19;

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
    
    int potVal = board.ldr.read();
    pitch = map(potVal, 0, 1023, 0, 127);

    if (pitch == previousPitch) return;
    noteOn(0x90, previousPitch, 0x00);
    previousPitch = pitch;
  
    noteOn(0x90, pitch, 0x6E);
  }

  board.rgb.setColor(pitch, pitch, pitch);
  board.ledmatrix.print(pitch);
}
