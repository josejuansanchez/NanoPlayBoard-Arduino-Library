// Expected JSON message: {"r": 120, "g": 2, "b": 34}

#include <NanoPlayBoard.h>
#include <ArduinoJson.h>

NanoPlayBoard board;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() <= 0) return;

  String json = Serial.readStringUntil('\n');
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);

  if (!root.success()) {
    Serial.println("{\"error\": \"Error parsing json message\"}");
    return;
  }

  int r = root["r"];
  int g = root["g"];
  int b = root["b"];

  board.rgb.setColor(r, g, b);
}
