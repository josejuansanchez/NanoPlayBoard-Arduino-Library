// Expected JSON message: {"text": "Hola mundo!"}

#include <ArduinoJson.h>
#include <NanoPlayBoard.h>

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

  String text = root["text"];
  board.ledmatrix.print(text);
}
