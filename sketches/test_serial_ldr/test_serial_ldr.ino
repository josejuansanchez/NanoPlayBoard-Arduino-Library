int ldrPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(ldrPin);
  Serial.println(sensorValue);
  delay(100);
}
