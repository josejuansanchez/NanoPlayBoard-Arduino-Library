#ifndef PINS_MODEL_B
#define PINS_MODEL_B

#undef PIN_POT
#define PIN_POT         A7

#undef PIN_LDR
#define PIN_LDR         A6

#undef PIN_DATA_IN
#define PIN_DATA_IN     12

#undef PIN_CLOCK_IN
#define PIN_CLOCK_IN    13

#undef PIN_CLOCK_OUT
#define PIN_CLOCK_OUT   4

#define PIN_SERVO_1     5
#define PIN_SERVO_2     6

#define PIN_HC148_A0    A0
#define PIN_HC148_A1    A1

#define PIN_ROTARY_ENCODER_A    2
#define PIN_ROTARY_ENCODER_B    A2

#define PIN_BLUETOOTH_RX        0
#define PIN_BLUETOOTH_TX        1

#define PIN_LEDMATRIX_VALUES    {128, 64, 32, 16, 8}

#endif