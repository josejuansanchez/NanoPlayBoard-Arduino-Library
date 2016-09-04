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
    
    int potVal = board.potentiometer.read();
    pitch = map(potVal, 0, 1023, 0, 127);

    if (pitch == previousPitch) return;
    noteOn(0x90, previousPitch, 0x00);
    previousPitch = pitch;
  
    noteOn(0x90, pitch, 0x6E);
  }

  if (pitch <= 40) {
    board.rgb.setColor(255, 0, 0);
  } else if (pitch <= 80) {
    board.rgb.setColor(0, 255, 0);
  } else {
    board.rgb.setColor(0, 0, 255);
  }
  
  board.ledmatrix.print(pitch);
}
