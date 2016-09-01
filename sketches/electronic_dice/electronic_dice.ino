#include <NanoPlayBoard.h>

NanoPlayBoard board;

int pot, potPrevious;
int index;

void setup() {
  randomSeed(analogRead(A0));
}

void loop() {
  byte pattern[6][5] = 
    {{0, 0, 16, 0, 0},
    {64, 0, 0, 0, 4},
    {64, 0, 16, 0, 4},
    {68, 0, 0, 0, 68},
    {68, 0, 16, 0, 68},
    {84, 0, 0, 0, 84}};

  pot = board.potentiometer.read();
  if (pot != potPrevious) {
    potPrevious = pot;
    index = random(0, 5);
    board.ledmatrix.print(pattern[index]);    
  }
}
