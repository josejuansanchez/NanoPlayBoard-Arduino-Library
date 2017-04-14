#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  float temperature = board.dht.readTemperature();

  if (isnan(temperature)) {
    board.ledmatrix.print("?");
  }
  else {
    board.ledmatrix.printNumber(temperature);
  }
}
