int potPin = A1;
int buzzerPin = 3;

void setup() {

}

void loop() {
  int potVal = analogRead(potPin);
  tone(buzzerPin, potVal);
  delay(100); 
}
