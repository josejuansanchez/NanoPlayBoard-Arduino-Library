/*
  Configuration.h - Library for the Arduino NanoPlayBoard
  Created by José Juan Sánchez, September 15, 2016.
  Released under GNU GPL v3.
*/

#ifndef Configuration_h
#define Configuration_h

#define BOARD_MODEL_B

#ifdef BOARD_MODEL_B
  #include "PinsModelB.h"
#else
  #include "PinsModelA.h"
#endif

#endif
