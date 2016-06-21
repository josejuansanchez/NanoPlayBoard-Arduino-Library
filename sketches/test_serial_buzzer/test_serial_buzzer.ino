int buzzerPin = 3;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int value = Serial.parseInt();
    tone(buzzerPin, value);
    delay(100);     
  }  
}
