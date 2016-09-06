// Expected JSON message: {"frequency": 440, "duration": 125}

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

  unsigned int frequency = root["frequency"];
  unsigned long duration = root["duration"];
  
  board.buzzer.playTone(frequency, duration);
}
