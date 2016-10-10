#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  float humidity = board.dht.readHumidity();

  if (isnan(humidity)) {
    board.ledmatrix.print("?");
  }
  else {
    board.ledmatrix.printInLandscape(humidity);
  }
}
