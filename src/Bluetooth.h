/*
  Bluetooth.h - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 22, 2016.
  Released under GNU GPL v3.
*/

#ifndef Bluetooth_h
#define Bluetooth_h

#include "Arduino.h"
#include "PinsModelB.h"
#include <SoftwareSerial.h>

class Bluetooth: public SoftwareSerial
{
  public:
    Bluetooth();
    Bluetooth(uint8_t rx, uint8_t tx);
};

#endif
