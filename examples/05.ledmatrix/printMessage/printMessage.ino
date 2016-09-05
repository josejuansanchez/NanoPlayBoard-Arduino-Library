#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  board.ledmatrix.setScrollSpeed(10);
  board.ledmatrix.print("H o l a  m u n d o!");
}

