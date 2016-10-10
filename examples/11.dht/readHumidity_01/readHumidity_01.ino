#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {
  board.bluetooth.begin(9600);
}

void loop() {
  float humidity = board.dht.readHumidity();

  if (isnan(humidity)) {
    board.bluetooth.println("Error reading humidity!");
  }
  else {
    board.bluetooth.print("Humidity: ");
    board.bluetooth.print(humidity);
    board.bluetooth.println(" %");
  }
  delay(1000);
}
