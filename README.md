# Library for the Arduino Nano Playboard

This library enables easy access to the sensors and actuators of the [Arduino Nano PlayBoard][1]. The Arduino Nano PlayBoard is a board designed by [Antonio Morales][2].

The sensors available on the board are a light sensor and a potentiometer. The actuators available on the board are a 7x5 matrix LED, a RGB LED and a piezo buzzer.

For more information about the board please visit us at:  

* https://github.com/AntonioMR/Arduino-Nano-Play-Board

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


[1]: http://github.com/AntonioMR/Arduino-Nano-Play-Board
[2]: http://twitter.com/antonio1010mr
[3]: http://josejuansanchez.org
