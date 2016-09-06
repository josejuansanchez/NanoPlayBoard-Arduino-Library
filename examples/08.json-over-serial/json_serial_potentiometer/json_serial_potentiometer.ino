#include <NanoPlayBoard.h>
#include <ArduinoJson.h>

NanoPlayBoard board;

int lastPotValue = -1;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int potValue = board.potentiometer.read();

  if (potValue == lastPotValue) return;
  lastPotValue = potValue;

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["potentiometer"] = potValue;
  root.printTo(Serial);

  delay(100);
}
