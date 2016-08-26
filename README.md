# Library for the Arduino Nano Play Board

This library enables easy access to the sensors and actuators of the [Arduino Nano Play Board][1]. The [Arduino Nano Play Board][1] is a board designed by [Antonio Morales][2] and it was designed for an introductory workshop about soldering organized by [HackLab Almería][3]. You can see the gallery of images [here][4].

This board may be an **excellent educational resource** for those students who want **to learn basic electronic and programming**.

The sensors available on the board are a light sensor and a potentiometer.  
The actuators available on the board are a 7x5 matrix LED, a RGB LED and a piezo buzzer.

For more information about the board please visit us at:  

* http://github.com/AntonioMR/Nano-Play-Board

For more information about the project please visit us at:  

* http://nanoplayboard.org

![upperside](https://raw.githubusercontent.com/josejuansanchez/NanoPlayBoard/master/NanoPlayBoard/extras/upperside.png)
![underside](https://raw.githubusercontent.com/josejuansanchez/NanoPlayBoard/master/NanoPlayBoard/extras/underside.png)

## Installation

* [Download the library][releases].
* Go to the Arduino IDE, select `Sketch > Import Library > Add library .ZIP`
* Restart the Arduino IDE.
* Now the example sketches will be available in the menu `File > Examples > NanoPlayBoard`.

![examples](https://raw.githubusercontent.com/josejuansanchez/NanoPlayBoard/master/NanoPlayBoard/extras/examples.png)

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

You can use hexadecimal color strings with or without leading `#`.

```c++
board.rgb.setColor("#FF0000");
board.rgb.setColor("FF0000");  
```

### LED Matrix

```c++
NanoPlayBoard board;

board.ledmatrix.print("H o l a  m u n d o!");
```

The library allows you to control the scroll speed that is used to display the text in the led matrix.

```c++
NanoPlayBoard board;

board.ledmatrix.setScrollSpeed(10);
board.ledmatrix.print("H o l a  m u n d o!");
```

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
[releases]: https://github.com/josejuansanchez/NanoPlayBoard/releases
