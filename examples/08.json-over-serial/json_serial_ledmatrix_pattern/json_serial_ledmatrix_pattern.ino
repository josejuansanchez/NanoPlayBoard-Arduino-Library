// Expected JSON message: {"pattern":[16, 72, 8, 72, 16]}

#include <ArduinoJson.h>
#include <NanoPlayBoard.h>

NanoPlayBoard board;

byte pattern[5];

void setup() {
  Serial.begin(115200);
}

void loop() {
  board.ledmatrix.print(pattern);

  if (Serial.available() <= 0) return;

  String json = Serial.readStringUntil('\n');
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);

  if (!root.success()) {
    Serial.println("{\"error\": \"Error parsing json message\"}");
    return;
  }

  pattern[0] = root["pattern"][0];
  pattern[1] = root["pattern"][1];
  pattern[2] = root["pattern"][2];
  pattern[3] = root["pattern"][3];
  pattern[4] = root["pattern"][4];
}
