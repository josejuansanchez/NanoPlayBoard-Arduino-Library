// SRCLK (Serial clock)
// SH_CP
// Clock
int SRCLK_pin = 12;

// RCLK (Register Clock)
// ST_CP
// Latch
int RCLK_pin = A7;

// SER (Serial)
// DS
// Data
int SER_pin = 13;

#define MAX_ROWS 7
#define MAX_COLS 5

int cols[MAX_COLS] = {2, 4, 5, A2, A3};

boolean rows_test_1[MAX_ROWS+1] = {1, 1, 1, 1, 1, 1, 1, 1};
boolean rows_test_2[MAX_ROWS+1] = {0, 0, 0, 1, 0, 0, 0, 0};

void setup() {
  pinMode(SRCLK_pin, OUTPUT);
  pinMode(RCLK_pin, OUTPUT);
  pinMode(SER_pin, OUTPUT);

  for(int i=0; i<MAX_COLS; i++) {
    digitalWrite(cols[i], LOW);
  }
}

void writeShiftRegister(boolean registers[]) {
  int t = 100;
  digitalWrite(RCLK_pin, LOW);

  for(int i = MAX_ROWS; i >= 0; i--) {
    digitalWrite(SRCLK_pin, LOW);
    //delayMicroseconds(t);
    delay(5);

    digitalWrite(SER_pin, registers[i]);
    //delayMicroseconds(t);
    delay(5);
    
    digitalWrite(SRCLK_pin, HIGH);
    //delayMicroseconds(2*t);
  }  
  //delayMicroseconds(t);
  digitalWrite(RCLK_pin, HIGH);
  //delayMicroseconds(t);
}

void loop() {
  writeShiftRegister(rows_test_1);

  digitalWrite(cols[0], HIGH);
  digitalWrite(cols[1], LOW);
  digitalWrite(cols[2], LOW);
  digitalWrite(cols[3], LOW);
  digitalWrite(cols[4], HIGH);
   
  delay(200);

  digitalWrite(cols[0], LOW);
  digitalWrite(cols[1], LOW);
  digitalWrite(cols[2], LOW);
  digitalWrite(cols[3], LOW);
  digitalWrite(cols[4], LOW);
  
  writeShiftRegister(rows_test_2);

  digitalWrite(cols[0], HIGH);
  digitalWrite(cols[1], HIGH);
  digitalWrite(cols[2], HIGH);
  digitalWrite(cols[3], HIGH);
  digitalWrite(cols[4], HIGH);
  
  delay(200);
}
