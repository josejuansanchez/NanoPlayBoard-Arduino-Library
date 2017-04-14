# Library for the Arduino NanoPlayBoard [![Build Status](https://travis-ci.org/josejuansanchez/NanoPlayBoard-Arduino-Library.svg?branch=master)](https://travis-ci.org/josejuansanchez/NanoPlayBoard-Arduino-Library)

This library enables easy access to the sensors and actuators of the [Arduino NanoPlayBoard][1]. The [Arduino NanoPlayBoard][1] is a board designed by [Antonio Morales][2] and it was designed for an introductory workshop about soldering organized by [HackLab Almería][3]. You can see the gallery of images [here][4].

This board may be an **excellent educational resource** for those students who want **to learn basic electronic and programming**.

The sensors available on the board are a light sensor and a potentiometer.  
The actuators available on the board are a 7x5 matrix LED, a RGB LED and a piezo buzzer.

For more information about the board please visit us at:  

* http://github.com/AntonioMR/Nano-Play-Board

For more information about the project please visit us at:  

* http://nanoplayboard.org

## PCB
### Upperside
![upperside][upperside]

### Underside
![underside][underside]

## Installation
### Using the Library Manager
* Open the Arduino IDE and select `Sketch > Include Library > Manage Libraries`.
* Search `NanoPlayBoard` in the Library Manger.
* Select the version of the library you want to install.
* Click on install and wait for the IDE to install the new library.

![library_manager][library_manager]

### Importing a .zip Library
* [Download the library][releases].
* Open the Arduino IDE and select `Sketch > Include Library > Add .ZIP Library`.
* Restart the Arduino IDE.

### Examples
Once the library has been successfully installed, the example sketches will be available in the IDE.
* Select `File > Examples > NanoPlayBoard`.

![examples][examples]

## Quick start
### Include the library and declare a `NanoPlayBoard` object.

```c++
#include <NanoPlayBoard.h>

NanoPlayBoard board;

...
```

### Potentiometer
* read
```c++
int value = board.potentiometer.read();
```

* scaleTo
```c++
int value = board.potentiometer.scaleTo(0, 99);
```

### LDR
* read
```c++
int value = board.ldr.read();
```

* scaleTo
```c++
int value = board.ldr.scaleTo(0, 99);
```

### Buzzer
* playTone
```c++
board.buzzer.playTone(440);
```

* stopTone
```c++
board.buzzer.stopTone();
```

### LED RGB
* setColor
```c++
board.rgb.setColor(255, 0, 0);
```

You can use hexadecimal color strings with or without leading `#`.

```c++
board.rgb.setColor("#FF0000");
board.rgb.setColor("FF0000");  
```

* setIntensity
```c++
board.rgb.setIntensity(25);
```

* on
```c++
board.rgb.on();
```

* off
```c++
board.rgb.off();
```

* toggle
```c++
board.rgb.toggle();
```

### LED Matrix
* print
```c++
board.ledmatrix.print("H o l a  m u n d o!");
```

* setScrollSpeed

```c++
board.ledmatrix.setScrollSpeed(10);
board.ledmatrix.print("H o l a  m u n d o!");
```
The library allows you to control the scroll speed that is used to display the text on the led matrix.

* printNumber
```c++
board.ledmatrix.printNumber(99);
```

## Libraries used in this project

* [Arduino library for the DHT series of low cost temperature/humidity sensors][6].
* [Software I2C Arduino library][7].
* [NewPing Arduino library][8].

## Credits

This library has been developed by [Antonio Morales][2] and [José Juan Sánchez][5].

## License

```
Copyright 2016 Antonio Morales and José Juan Sánchez

Licensed under the GNU General Public License, Version 3 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.gnu.org/licenses/gpl-3.0.en.html

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```

[1]: http://github.com/AntonioMR/Nano-Play-Board
[2]: http://twitter.com/antonio1010mr
[3]: http://hacklabalmeria.net
[4]: https://goo.gl/photos/VKdNkxRcpEW4yBa47
[5]: http://josejuansanchez.org
[6]: https://github.com/adafruit/DHT-sensor-library
[7]: https://github.com/felias-fogg/SoftI2CMaster
[8]: https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home

[releases]: https://github.com/josejuansanchez/NanoPlayBoard/releases
[upperside]: https://github.com/josejuansanchez/NanoPlayBoard-Arduino-Library/blob/master/extras/upperside_v1.png
[underside]: https://github.com/josejuansanchez/NanoPlayBoard-Arduino-Library/blob/master/extras/underside_v1.png
[library_manager]: https://github.com/josejuansanchez/NanoPlayBoard-Arduino-Library/blob/master/extras/library_manager.png
[examples]: https://github.com/josejuansanchez/NanoPlayBoard-Arduino-Library/blob/master/extras/examples.png
