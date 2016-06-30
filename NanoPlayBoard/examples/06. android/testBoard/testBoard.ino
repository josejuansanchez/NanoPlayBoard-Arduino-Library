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

  int sketchId = root["sketchId"];

  while(1) {
    switch(sketchId) {
      case 0: loadPotentiometerSketch();
              break;

      case 1: loadLDRSketch();
              break;

      case 2: loadRGBSketch();
              break;

      case 3: loadBuzzerSketch();
              break;

      case 4: loadLedMatrixSketch();
              break;              
    }
  }
}

//---------------------------------

void loadPotentiometerSketch() {
  //int potValue = board.potentiometer.read();
  int potValue = analogRead(A1);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["potentiometer"] = potValue;
  root.printTo(Serial);
  delay(100);
}

//---------------------------------

void loadLDRSketch() {
  int ldrValue = board.ldr.read();

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["ldr"] = ldrValue;
  root.printTo(Serial);
  delay(100);
}

//---------------------------------

void loadRGBSketch() {
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

  board.rgb.write(r, g, b);
}

//---------------------------------

void loadBuzzerSketch() {
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

//---------------------------------

void loadLedMatrixSketch() {
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
