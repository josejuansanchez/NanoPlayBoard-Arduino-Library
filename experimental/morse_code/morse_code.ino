#include <NanoPlayBoard.h>
#include "MorseCodeAlphabet.h"

#define WPM         20
#define DOT_LENGTH  1200 / WPM
#define PITCH       550

NanoPlayBoard board;

void setup() {
  Serial.begin(9600);
}

void loop() {
  String message = " ... --- ... ";

  for(int i = 0; i < message.length(); i++) {
    switch(message[i]) {
      case '.':
        board.rgb.on();
        board.buzzer.playTone(PITCH);
        delay(DOT_LENGTH);
        board.rgb.off();
        board.buzzer.stopTone();
        delay(DOT_LENGTH);
        break;

      case '-':
        board.rgb.on();
        board.buzzer.playTone(PITCH);
        delay(DOT_LENGTH * 3);
        board.rgb.off();
        board.buzzer.stopTone();
        delay(DOT_LENGTH);
        break;

      case ' ':
        board.rgb.off();
        board.buzzer.stopTone();
        delay(DOT_LENGTH);
        break;
    }
  }
}
