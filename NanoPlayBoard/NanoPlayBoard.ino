#include "src/NanoPlayBoard.h"

NanoPlayBoard board;

void setup() {
  Serial.begin(9600);
}

void loop() {
  testPotentiometer();
}

void testPotentiometer() {
  int value = board.potentiometer.read();
  Serial.println(value);
  delay(100);
}

void testRGB() {
  board.rgb.write(255, 0, 0);  
  delay(100);
  board.rgb.write(0, 255, 0);
  delay(100);
  board.rgb.write(0, 0, 255);  
  delay(100);    
}

void testLDR() {
  int value = board.ldr.read();  
  Serial.println(value);
  delay(100);
}

void testBuzzer() {
  board.buzzer.playTone(440);
  delay(100);
}

