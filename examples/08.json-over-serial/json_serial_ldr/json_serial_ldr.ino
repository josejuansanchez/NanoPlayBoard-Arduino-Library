#include <NanoPlayBoard.h>
#include <ArduinoJson.h>

NanoPlayBoard board;

int lastLdrValue = -1;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int ldrValue = board.ldr.read();

  if (ldrValue == lastLdrValue) return;
  lastLdrValue = ldrValue;

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["ldr"] = ldrValue;
  root.printTo(Serial);

  delay(100);
}
