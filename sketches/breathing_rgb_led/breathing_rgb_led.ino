// Reference: Arduino playground by Bostjan Jerko

#include <NanoPlayBoard.h>
#include <math.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  float r = 255 * exp(sin(millis() / 2000.0 * PI)) / exp(1);
  float g = 255 * exp(sin(millis() / 1500.0 * PI)) / exp(1);
  float b = 255 * exp(sin(millis() / 1000.0 * PI)) / exp(1);
  board.rgb.setColor(r, g, b);
}
