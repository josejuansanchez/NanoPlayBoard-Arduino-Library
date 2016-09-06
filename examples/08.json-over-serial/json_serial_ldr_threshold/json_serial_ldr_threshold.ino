#include <NanoPlayBoard.h>
#include <ArduinoJson.h>

#define THRESHOLD 25

NanoPlayBoard board;

int lastLdrValue = -1;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int ldrValue = board.ldr.read();
  float epsilon = (lastLdrValue * THRESHOLD) / 100.0;
  
  if ((ldrValue > lastLdrValue - epsilon) && 
      (ldrValue < lastLdrValue + epsilon))
    return;
  
  lastLdrValue = ldrValue;
  
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["ldr"] = ldrValue;
  root.printTo(Serial);
}
