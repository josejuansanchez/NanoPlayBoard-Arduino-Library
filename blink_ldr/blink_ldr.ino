int ldrPin = A0;
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  digitalWrite(ledPin, HIGH);
  delay(ldrValue);
  digitalWrite(ledPin, LOW);
  delay(ldrValue);
}
