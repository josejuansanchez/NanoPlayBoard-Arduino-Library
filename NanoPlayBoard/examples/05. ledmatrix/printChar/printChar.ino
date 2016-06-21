#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  char numbers[] = "0123456789";
  int speed = 15;
  
  for(int i = 0; i<strlen(numbers); i++) {
    for(int j = 0; j < speed; j++) {
      board.ledmatrix.print(numbers[i]);
    }
    delay(2);
  }
}
