#include <NanoPlayBoard.h>

NanoPlayBoard board;

void setup() {

}

void loop() {
  if (board.buttons.left.isPressed()) {
    board.rgb.setColor("FF0000");
    board.rgb.on();
  }

  if (board.buttons.right.isPressed()) {
    board.rgb.setColor("00FF00");
    board.rgb.on();
  }

  if (board.buttons.down.isPressed()) {
    board.rgb.setColor("0000FF");
    board.rgb.on();
  }

  board.rgb.off();
}
