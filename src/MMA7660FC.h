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

#ifndef MMA7660FC_h
#define MMA7660FC_h

#include <Arduino.h>

// Hardware address
#define MMA7660FC_I2C_ADDRESS 0x98  // MMA7660FC hardware address 0x4c << 1

// NMA7660FC internal registers definition
/**
* | Address | Name  | Definition           |  Bit 7  |  Bit 6  |  Bit 5  |  Bit 4  |  Bit 3  |  Bit 2  |   Bit 1  |   Bit 0  |
* |---------|-------|----------------------|---------|---------|---------|---------|---------|---------|----------|----------|
* |  0X00   | XOUT  | 6-bit output value X |    -    |  Alert  | XOUT[5] | XOUT[4] | XOUT[3] | XOUT[2] |  XOUT[1] |  XOUT[0] |
* |---------|-------|----------------------|---------|---------|---------|---------|---------|---------|----------|----------|
* |  0X01   | YOUT  | 6-bit output value Y |    -    |  Alert  | YOUT[5] | YOUT[4] | YOUT[3] | YOUT[2] |  YOUT[1] |  YOUT[0] |
* |---------|-------|----------------------|---------|---------|---------|---------|---------|---------|----------|----------|
* |  0X02   | ZOUT  | 6-bit output value Z |    -    |  Alert  | ZOUT[5] | ZOUT[4] | ZOUT[3] | ZOUT[2] |  ZOUT[1] |  ZOUT[0] |
* |---------|-------|----------------------|---------|---------|---------|---------|---------|---------|----------|----------|
* |  0X03   | TILT  | Tilt Status          |  Shake  |   Alert |   Tap   | PoLa[2] | PoLa[1] | PoLa[0] | BaFro[1] | BaFro[0] |
* |---------|-------|----------------------|---------|---------|---------|---------|---------|---------|----------|----------|
* |  0X04   | SRST  | Sampling Rate Status |    0    |    0    |    0    |    0    |    0    |    0    |   AWSRS  |   AMSRS  |
* |---------|-------|----------------------|---------|---------|---------|---------|---------|---------|----------|----------|
* |  0X05   | SPCNT | Sleep Count          |  SC[7]  |  SC[6]  |  SC[5]  |  SC[4]  |  SC[3]  |  SC[2]  |   SC[1]  |   SC[0]  |
* |---------|-------|----------------------|---------|---------|---------|---------|---------|---------|----------|----------|
* |  0X06   | INTSU | Interrupt Setup      |  SHINTX |  SHINTY |  SHINTZ |   GINT  |  ASINT  |  PDINT  |   PLINT  |   FBINT  |
* |---------|-------|----------------------|---------|---------|---------|---------|---------|---------|----------|----------|
* |  0X07   | MODE  | Mode                 |   IAH   |   IPP   |   SCPS  |   ASE   |   AWE   |   TON   |     -    |    MODE  |
* |---------|-------|----------------------|---------|---------|---------|---------|---------|---------|----------|----------|
* |  0X08   |   SR  | Sample Rate Filter   | FILT[2] | FILT[1] | FILT[0] | AWSR[1] | AWSR[0] | AMSR[2] |  AMSR[1] |  AMSR[0] |
* |---------|-------|----------------------|---------|---------|---------|---------|---------|---------|----------|----------|
* |  0X09   |  PDET | Tap Detection        |   ZDA   |   YDA   |   XDA   | PDTH[4] | PDTH[3] | PDTH[2] |  PDTH[1] |  PDTH[0] |
* |---------|-------|----------------------|---------|---------|---------|---------|---------|---------|----------|----------|
* |  0X0A   |   PD  | Tap Debounce Count   |  PD[7]  |  PD[6]  |  PD[5]  |  PD[4]  |  PD[3]  |  PD[2]  |   PD[1]  |   PD[0]  |
* |---------|-------|----------------------|---------|---------|---------|---------|---------|---------|----------|----------|
* |  0X0B - 0x1F    |                        Factory Reserved                                                                |
* |---------|-------|--------------------------------------------------------------------------------------------------------|
*
* To write to the registers the MODE bit in the MODE (0x07) register must be set to 0, placing the device in Standby Mod
*/

#define XOUT 0x00       // 6-bits output value X
#define YOUT 0x01       // 6-bits output value Y
#define ZOUT 0x02       // 6-bits output value Z
#define TILT 0x03       // Tilt Status
#define SRST 0x04       // Sampling Rate Status
#define SPCNT 0x05      // Sleep Count
#define INTSU 0x06      // Interrupt Setup
#define MODE 0x07       // Mode Control Register
#define SR 0x08         // Sample Rate Register
#define PDET 0x09       // Tap Detection
#define PD 0x0A         // Tap Debounce Count

// constants for interrupt behavior definition
#define NONE 0x00
#define FRONT 0x01
#define BACK 0x02
#define UP 0x03
#define DOWN 0x04
#define LEFT 0x05
#define RIGHT 0x06
#define TAP 0x07
#define X_SHAKE 0x08
#define Y_SHAKE 0x09
#define Z_SHAKE 0x10
#define ALL 0xFF

class MMA7660FC {

  public:
    MMA7660FC();
    bool init();
    bool setSamplesPerSecond(const uint8_t &samples);
    bool enableInterrupts(const uint8_t &interrutp);
    bool disableInterrupts(const uint8_t &interrutp);
    bool enableAutoSleep();
    bool disableAutoSleep();
    bool enableAutoWake();
    bool disableAutoWake();
    bool setActiveMode();
    bool setStandbyMode();
    bool setMode(const uint8_t &mode);
    bool getMode(uint8_t &mode);
    uint8_t getX();
    uint8_t getY();
    uint8_t getZ();
    bool isFront();
    bool isBack();
    bool isUp();
    bool isDown();
    bool isLeft();
    bool isRight();
    bool isXTapped();
    bool isYTapped();
    bool isZTapped();
    bool isShaked();

  private:
    uint8_t _byteRead = 0;
    uint8_t _byteWrite = 0;
    uint8_t _modeR = 0;
    uint8_t _interruptR = 0;
    uint8_t _BaFro = 0;
    void _CPUSlowDown(int fac);
    bool _readRegister(const uint8_t &regRead, uint8_t &data);
    bool _writeRegister(const uint8_t &regWritten, const uint8_t &data);
};

#endif
