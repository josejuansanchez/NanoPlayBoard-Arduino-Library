#include "src/NanoPlayBoard.h"

#include "src/MatrizLed.h"
#include "src/Registro.h"

NanoPlayBoard board;

void setup() {
  Serial.begin(9600);
}

void loop() {
  testLedMatrix_Message();
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

void testLedMatrix_Char() {
    board.ledmatrix.print('A');
}

void testLedMatrix_Pattern() {
  byte pattern[5] = {
    0b00010000,
    0b01001000,
    0b00001000,
    0b01001000,
    0b00010000
    };

  board.ledmatrix.print(pattern);  
}

void testLedMatrix_Message() {
  board.ledmatrix.setScrollSpeed(20);
  board.ledmatrix.print("H o l a ");
}

