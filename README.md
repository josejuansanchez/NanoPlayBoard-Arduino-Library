# Library for the Arduino Nano Playboard

This library enables easy access to the sensors and actuators of the [Arduino Nano PlayBoard][1]. The Arduino Nano PlayBoard is a board designed by [Antonio Morales][2].

The sensors available on the board are a light sensor and a potentiometer. The actuators available on the board are a 7x5 matrix LED, a RGB LED and a piezo buzzer.

For more information about the board please visit us at:  

* https://github.com/AntonioMR/Arduino-Nano-Play-Board

## Installation

* [Download the library][releases].
* Go to the Arduino IDE, select `Sketch > Import Library > Add library .ZIP`
* Restart the Arduino IDE.
* Now the example sketches will be available in the menu `File > Examples > NanoPlayBoard`.

## Quick start

### Potentiometer

```c++
NanoPlayBoard board;

int value = board.potentiometer.read();
```

### LDR

```c++
NanoPlayBoard board;

int value = board.ldr.read();
```

### Buzzer

```c++
NanoPlayBoard board;

board.buzzer.playTone(440);
```

### LED RGB

```c++
NanoPlayBoard board;

board.rgb.write(255, 0, 0);  
```

### LED Matrix

```c++
NanoPlayBoard board;

board.ledmatrix.setScrollSpeed(10);
board.ledmatrix.print("H o l a  m u n d o!");
```

## Credits

This library has been developed by [Antonio Morales][2] and [José Juan Sánchez][3].

## License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

[1]: http://github.com/AntonioMR/Arduino-Nano-Play-Board
[2]: http://twitter.com/antonio1010mr
[3]: http://josejuansanchez.org
[releases]: https://github.com/josejuansanchez/NanoPlayBoard/releases
