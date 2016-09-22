/*
  Bluetooth.cpp - Library for the Arduino Nano PlayBoard
  Created by José Juan Sánchez, September 21, 2016.
  Released under GNU GPL v3.
*/

#include "Arduino.h"
#include "Bluetooth.h"

Bluetooth::Bluetooth(): SoftwareSerial(PIN_BLUETOOTH_RX, PIN_BLUETOOTH_TX) {}

Bluetooth::Bluetooth(uint8_t rx, uint8_t tx): SoftwareSerial(rx, tx)
{
  begin(9600);
}
