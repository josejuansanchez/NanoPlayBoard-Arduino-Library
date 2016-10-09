#include <NanoPlayBoard.h>
#include <ArduinoJson.h>

NanoPlayBoard board;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int ldrValue = board.ldr.read();
  int potValue = board.potentiometer.read();

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["potentiometer"] = potValue;
  root["ldr"] = ldrValue;
  root.printTo(Serial);
  
  delay(100);
}
