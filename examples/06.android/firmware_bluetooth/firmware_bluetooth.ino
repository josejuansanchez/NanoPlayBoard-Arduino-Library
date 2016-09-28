#include <ArduinoJson.h>
#include <NanoPlayBoard.h>
#include <SoftwareSerial.h>

// NanoPlayBoard 0.1
//SoftwareSerial btSerial(7, 8); // RX, TX

// NanoPlayBoard Rev-0.2
SoftwareSerial btSerial(0, 1); // RX, TX

NanoPlayBoard board;
String json;
int sketchId = -1;

//---------------------------------

// Functions definition
void btSerialEvent();
int getSketchId();
void runSketch();
void loadPotentiometerSketch();
void loadLDRSketch();
void loadRGBSketch();
void loadBuzzerSketch();
void loadLedMatrixPatternSketch();
void loadLedMatrixSketch();

//---------------------------------

void setup() {
  btSerial.begin(9600);
}

void loop() {
  btSerialEvent();
  runSketch();
}

void btSerialEvent() {
  int newSketchId = getSketchId();
  if (newSketchId != -1) sketchId = newSketchId;
}

//---------------------------------

int getSketchId() {
  if (btSerial.available() <= 0) return -1;
  //String json = btSerial.readStringUntil('\n');
  json = btSerial.readStringUntil('\n');
  StaticJsonBuffer<200> jsonBuffer;  
  JsonObject& root = jsonBuffer.parseObject(json);

  if (!root.success()) {
    btSerial.println("{\"error\": \"Error parsing json message\"}");
    return -1;
  }

  return root["sketchId"];
}

void runSketch() {
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

      case 5: loadLedMatrixPatternSketch();
              break;
    }
}

//---------------------------------
int lastPotValue = -1;
void loadPotentiometerSketch() {
  int potValue = board.potentiometer.read();

  if (potValue == lastPotValue) return;
  lastPotValue = potValue;

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["potentiometer"] = potValue;
  root.printTo(btSerial);
  
  // Bluetooth is waiting "\r\n"
  btSerial.println("");
  
  delay(100);
}

//---------------------------------
int lastLdrValue = -1;
void loadLDRSketch() {
  int ldrValue = board.ldr.read();

  if (ldrValue == lastLdrValue) return;
  lastLdrValue = ldrValue;

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["ldr"] = ldrValue;
  root.printTo(btSerial);
  
  // Bluetooth is waiting "\r\n"
  btSerial.println("");
  
  delay(100);
}

//---------------------------------

void loadRGBSketch() {
  if (json.length() <= 0) return;

  StaticJsonBuffer<200> jsonBuffer;  
  JsonObject& root = jsonBuffer.parseObject(json);

  if (!root.success()) {
    btSerial.println("{\"error\": \"Error parsing json message\"}");
    return;
  }

  int r = root["r"];
  int g = root["g"];
  int b = root["b"];

  board.rgb.setColor(r, g, b);
}

//---------------------------------

void loadBuzzerSketch() {
  if (json.length() <= 0) return;

  StaticJsonBuffer<200> jsonBuffer;  
  JsonObject& root = jsonBuffer.parseObject(json);

  if (!root.success()) {
    btSerial.println("{\"error\": \"Error parsing json message\"}");
    return;
  }

  unsigned int frequency = root["frequency"];
  unsigned long duration = root["duration"];
  
  board.buzzer.playTone(frequency, duration);
}

//---------------------------------

void loadLedMatrixSketch() {
  if (json.length() <= 0) return;
  
  StaticJsonBuffer<200> jsonBuffer;  
  JsonObject& root = jsonBuffer.parseObject(json);

  if (!root.success()) {
    btSerial.println("{\"error\": \"Error parsing json message\"}");
    return;
  }

  String text = root["text"];
  board.ledmatrix.print(text);  
}

//---------------------------------

void loadLedMatrixPatternSketch() {
  if (json.length() <= 0) return;
  
  StaticJsonBuffer<200> jsonBuffer;  
  JsonObject& root = jsonBuffer.parseObject(json);

  if (!root.success()) {
    btSerial.println("{\"error\": \"Error parsing json message\"}");
    return;
  }

  byte pattern[5];
  pattern[0] = root["pattern"][0];
  pattern[1] = root["pattern"][1];
  pattern[2] = root["pattern"][2];
  pattern[3] = root["pattern"][3];
  pattern[4] = root["pattern"][4];

  board.ledmatrix.print(pattern);
}
