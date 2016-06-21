int potPin = A1;
int ledPin = 13;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);
  digitalWrite(ledPin, HIGH);
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);
  delay(potValue);
  digitalWrite(ledPin, LOW);
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);  
  delay(potValue);
}
