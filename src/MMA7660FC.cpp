/**
 * NMA7660FC 3 axis Orientation/Motion Detection Sensor library
 * for the Nano-Play-Board educational board.
 *
 * Copyright (C) 2016 AntonioMR [https://github.com/AntonioMR/Nano-Play-Board]
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <Arduino.h>
#include "MMA7660FC.h"

// Define SDA pin as A4
#define SDA_PIN 4
#define SDA_PORT PORTC

// Define SDA pin as A5
#define SCL_PIN 5
#define SCL_PORT PORTC

#define I2C_TIMEOUT 100
#define I2C_NOINTERRUPT 0
#define I2C_SLOWMODE 1
#define FAC 1
#define I2C_CPUFREQ (F_CPU/FAC)
#define I2C_FASTMODE 0

#include "SoftI2CMaster.h"
#include <avr/io.h>


// Class constructor
MMA7660FC::MMA7660FC(){

  _modeR = B10000001;      // IAH = 1. Interrupt output /INT is active high
                          // IPP = 0. Interrupt output /INT is open-drain
                          // SCPS = 0. Sleep counter preescaler is divide-by-1
                          // ASE = 0. Auto-sleep is disabled
                          // AWE = 0. Auto- Wake is disabled
                          // TON = 0. Standby or Active Mode (depending on MODE)
                          // ----- 0 Not used
                          // MODE = 1. Active Mode

}


// Public Methods
bool MMA7660FC::init(){

  #if FAC != 1
    _CPUSlowDown(FAC);
  #endif

  if (!i2c_init()){
    Serial.println(F("Initialization error. SDA or SCL are low"));
    return 0;
  }

  if(!_writeRegister(MODE,_modeR)){
     Serial.println(F("Error writting register"));
     return 0;
  }
  return 1;
}

float MMA7660FC::getX(){
  int count = 0;
  do {
    if(!_readRegister(XOUT, _byteRead)) return 0;
  } while (bitRead(_byteRead,6) && count <= 3);
  if(count >= 5) return 0;
  else return _getAngleXY(_get2sComplement(_byteRead & 0x3F));
}

float MMA7660FC::getY(){
  int count = 0;
  do {
    if(!_readRegister(YOUT, _byteRead)) return 0;
  } while (bitRead(_byteRead,6) && count <= 3);
  if(count >= 5) return 0;
  else return _getAngleXY(_get2sComplement(_byteRead & 0x3F));
}

float MMA7660FC::getZ(){
  int count = 0;
  do {
    if(!_readRegister(ZOUT, _byteRead)) return 0;
  } while (bitRead(_byteRead,6) && count <= 3);
  if(count >= 5) return 0;
  else return _getAngleZ(_get2sComplement(_byteRead & 0x3F));
}

bool MMA7660FC::isFront(){
  if(!_readRegister(TILT, _byteRead) | bitRead(_byteRead, 6)) return 0;
  _BaFro = bitRead(_byteRead,1) * bit(1) + bitRead(_byteRead,0) * bit(0);
  if (_BaFro != B01) return 0;
  return 1;
  }

bool MMA7660FC::isBack(){
  if(!_readRegister(TILT, _byteRead) | bitRead(_byteRead, 6)) return 0;
  _BaFro = bitRead(_byteRead,1) * bit(1) + bitRead(_byteRead,0) * bit(0);
  if (_BaFro != B10) return 0;
  return 1;
}

bool MMA7660FC::isUp(){
  if(!_readRegister(TILT, _byteRead) | bitRead(_byteRead, 6)) return 0;
  _PoLa = bitRead(_byteRead,4) * bit(2) + bitRead(_byteRead,3) * bit(1) + bitRead(_byteRead,2) * bit(0);
  if (_PoLa != B110) return 0;
  return 1;
}

bool MMA7660FC::isDown(){
  if(!_readRegister(TILT, _byteRead) | bitRead(_byteRead, 6)) return 0;
  _PoLa = bitRead(_byteRead,4) * bit(2) + bitRead(_byteRead,3) * bit(1) + bitRead(_byteRead,2) * bit(0);
  if (_PoLa != B101) return 0;
  return 1;
}

bool MMA7660FC::isLeft(){
  if(!_readRegister(TILT, _byteRead) | bitRead(_byteRead, 6)) return 0;
  _PoLa = bitRead(_byteRead,4) * bit(2) + bitRead(_byteRead,3) * bit(1) + bitRead(_byteRead,2) * bit(0);
  if (_PoLa != B001) return 0;
  return 1;
}

bool MMA7660FC::isRight(){
  if(!_readRegister(TILT, _byteRead) | bitRead(_byteRead, 6)) return 0;
  _PoLa = bitRead(_byteRead,4) * bit(2) + bitRead(_byteRead,3) * bit(1) + bitRead(_byteRead,2) * bit(0);
  if (_PoLa != B010) return 0;
  return 1;
}

bool MMA7660FC::enableInterrupts(const uint8_t &interrutp){
    if (!setStandbyMode()) return 0;

    switch (interrutp) {
      case NONE:
        if (!true ){
          setActiveMode();
          return 0;
        }
      break;

      case FRONT:
        if (!true ){
          setActiveMode();
          return 0;
        }
      break;

      case BACK:
        if (!true ){
          setActiveMode();
          return 0;
        }
      break;

      case UP:
        if (!true ){
          setActiveMode();
          return 0;
        }
      break;

      case DOWN:
        if (!true ){
          setActiveMode();
          return 0;
        }
      break;

      case LEFT:
        if (!true ){
          setActiveMode();
          return 0;
        }
      break;

      case RIGHT:
        if (!true ){
          setActiveMode();
          return 0;
        }
      break;

      case TAP:
        if (!true ){
          setActiveMode();
          return 0;
        }
      break;

      case X_SHAKE:
        if (!true ){
          setActiveMode();
          return 0;
        }
      break;

      case Y_SHAKE:
        if (!true ){
          setActiveMode();
          return 0;
        }
      break;

      case Z_SHAKE:
        if (!true ){
          setActiveMode();
          return 0;
        }
      break;

      case ALL:
        if (!true ){
          setActiveMode();
          return 0;
        }
      break;

    }
    return 1;
}

bool MMA7660FC::disableInterrupts(const uint8_t &interrutp){
  switch (interrutp) {
    case NONE:
      if (!true ){
        setActiveMode();
        return 0;
      }
    break;

    case FRONT:
      if (!true ){
        setActiveMode();
        return 0;
      }
    break;

    case BACK:
      if (!true ){
        setActiveMode();
        return 0;
      }
    break;

    case UP:
      if (!true ){
        setActiveMode();
        return 0;
      }
    break;

    case DOWN:
      if (!true ){
        setActiveMode();
        return 0;
      }
    break;

    case LEFT:
      if (!true ){
        setActiveMode();
        return 0;
      }
    break;

    case RIGHT:
      if (!true ){
        setActiveMode();
        return 0;
      }
    break;

    case TAP:
      if (!true ){
        setActiveMode();
        return 0;
      }
    break;

    case X_SHAKE:
      if (!true ){
        setActiveMode();
        return 0;
      }
    break;

    case Y_SHAKE:
      if (!true ){
        setActiveMode();
        return 0;
      }
    break;

    case Z_SHAKE:
      if (!true ){
        setActiveMode();
        return 0;
      }
    break;

    case ALL:
      if (!true ){
        setActiveMode();
        return 0;
      }
    break;

  }
  return 1;
}

bool MMA7660FC::enableAutoSleep(){
  if(!_readRegister(MODE, _modeR)) return 0;
  _modeR |= 0x10;
  if(!_writeRegister(MODE, _modeR)) return 0;
  return 1;
}

bool MMA7660FC::disableAutoSleep(){
  if(!_readRegister(MODE, _modeR)) return 0;
  _modeR &= 0xEF;
  if(!_writeRegister(MODE, _modeR)) return 0;
  return 1;
}

bool MMA7660FC::enableAutoWake(){
  if(!_readRegister(MODE, _modeR)) return 0;
  _modeR |= 0x08;
  if(!_writeRegister(MODE, _modeR)) return 0;
  return 1;
}

bool MMA7660FC::disableAutoWake(){
  if(!_readRegister(MODE, _modeR)) return 0;
  _modeR &= 0xF7;
  if(!_writeRegister(MODE, _modeR)) return 0;
  return 1;
}

bool MMA7660FC::setActiveMode(){
  if(!_readRegister(MODE, _modeR)) return 0;
  _modeR |= 0x01;
  if(!_writeRegister(MODE, _modeR)) return 0;
  return 1;
}

bool MMA7660FC::setStandbyMode(){
  if(!_readRegister(MODE, _modeR)) return 0;
  _modeR &= 0xFE;
  if(!_writeRegister(MODE, _modeR)) return 0;
  return 1;
}

bool MMA7660FC::setMode(const uint8_t &mode){
  if(!_writeRegister(MODE, mode)) return 0;
  return 1;
}

bool MMA7660FC::getMode(uint8_t &mode){
  if(!_readRegister(MODE, mode)) return 0;
  return 1;
}

bool MMA7660FC::isXTapped(){
  return 0;
}

bool MMA7660FC::isYTapped(){
  return 0;
}

bool MMA7660FC::isZTapped(){
  return 0;
}

bool MMA7660FC::isShaked(){
  return 0;
}

// Private Methods
bool MMA7660FC::_readRegister(const uint8_t &regRead, uint8_t &data){

  if (!i2c_start(MMA7660FC_I2C_ADDRESS | I2C_WRITE)){
    Serial.println("fail starting I2C communication 1");
    i2c_stop();
    return 0;
  }

  if (!i2c_write(regRead)){
    Serial.println("fail writting register to read");
    i2c_stop();
    return 0;
  }

  if (!i2c_rep_start(MMA7660FC_I2C_ADDRESS | I2C_READ)){
    Serial.println("fail starting I2C communication 2");
    i2c_stop();
    return 0;
  }

  data = i2c_read(true);
  i2c_stop();
  return 1;
}

bool MMA7660FC::_writeRegister(const uint8_t &regWritten, const uint8_t &data){

  if (!i2c_start(MMA7660FC_I2C_ADDRESS | I2C_WRITE)){
    i2c_stop();
    return 0;
  }

  if (!i2c_write(regWritten)){
    i2c_stop();
    return 0;
  }

  if (!i2c_write(data)){
    i2c_stop();
    return 0;
  }

  i2c_stop();
  return 1;
}

void MMA7660FC::_CPUSlowDown(int fac) {
  // slow down processor by a fac
  CLKPR = _BV(CLKPCE);
  CLKPR = _BV(CLKPS1) | _BV(CLKPS0);
}

int MMA7660FC::_get2sComplement(uint8_t value){
  if (!bitRead(value, 5)) return value;
  else return (-64-(~value+1));
}

float MMA7660FC::_getAngleXY(int value){
  if (value == 0) return float(0);
  else if (value >= 1 && value <=21) return float(_XYAngles[value-1]);
  else if (value >= -21 && value <=-1) return float(-_XYAngles[-value-1]);
  else return float(0);
}

float MMA7660FC::_getAngleZ(int value){
  if (value == 0) return float(90);
  else if (value >= 1 && value <=21) return float(_ZAngles[value-1]);
  else if (value >= -21 && value <=-1) return float(-_ZAngles[-value-1]);
  else return float(0);
}
