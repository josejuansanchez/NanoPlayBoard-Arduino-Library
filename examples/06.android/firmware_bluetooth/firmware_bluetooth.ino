#include <ArduinoJson.h>
#include <NanoPlayBoard.h>
#include <SoftwareSerial.h>

// NanoPlayBoard 0.1
//SoftwareSerial btSerial(7, 8); // RX, TX

// NanoPlayBoard Rev-0.2
SoftwareSerial btSerial(0, 1); // RX, TX

NanoPlayBoard board;
int message_id;
String json;

int last_pot_value = -1;
int last_ldr_value = -1;

//---------------------------------

#define ID_POTENTIOMETER_READ       10
#define ID_POTENTIOMETER_SCALE_TO   11
#define ID_POTENTIOMETER_STOP       12

#define ID_LDR_READ                 20
#define ID_LDR_SCALE_TO             21

#define ID_RGB_ON                   30
#define ID_RGB_OFF                  31
#define ID_RGB_TOGGLE               32
#define ID_RGB_SET_COLOR            33
#define ID_RGB_SET_INTENSITY        34

#define ID_BUZZER_PLAY_TONE         40
#define ID_BUZZER_STOP_TONE         41

#define ID_LEDMATRIX_PRINT_CHAR     50
#define ID_LEDMATRIX_PRINT_PATTERN  51
#define ID_LEDMATRIX_PRINT_STRING   52
#define ID_LEDMATRIX_PRINT_IN_LAND  53

//---------------------------------

// Functions definition
void btSerialEvent();
int getMessageId();
void doMessageAction();
void potentiometerRead();
void potentiometerScaleTo();
void ldrRead();
void ldrScaleTo();
void rgbOn();
void rgbOff();
void rgbToggle();
void rgbSetColor();
void buzzerPlayTone();
void ledmatrixPrintPattern();
void ledmatrixPrintString();

//---------------------------------

void setup() {
  btSerial.begin(9600);
}

void loop() {
  btSerialEvent();
  doMessageAction();
}

void btSerialEvent() {
  int new_message_id = getMessageId();
  if (new_message_id != -1) message_id = new_message_id;
}

//---------------------------------

int getMessageId() {
  if (btSerial.available() <= 0) return -1;
  json = btSerial.readStringUntil('\n');
  StaticJsonBuffer<200> json_buffer;
  JsonObject& root = json_buffer.parseObject(json);

  if (!root.success()) {
    btSerial.println("{\"error\": \"Error parsing json message\"}");
    return -1;
  }

  return root["id"];
}

//---------------------------------

void doMessageAction() {
  switch(message_id) {
    case ID_POTENTIOMETER_READ:
      potentiometerRead();
      break;

    case ID_POTENTIOMETER_SCALE_TO:
      potentiometerScaleTo();
      break;

    case ID_POTENTIOMETER_STOP:
      message_id = -1;
      break;

    case ID_LDR_READ:
      ldrRead();
      break;

    case ID_LDR_SCALE_TO:
      ldrScaleTo();
      break;

    case ID_RGB_ON:
      rgbOn();
      break;

    case ID_RGB_OFF:
      rgbOff();
      break;

    case ID_RGB_TOGGLE:
      rgbToggle();
      message_id = -1;
      break;

    case ID_RGB_SET_COLOR:
      rgbSetColor();
      break;

    case ID_BUZZER_PLAY_TONE:
      buzzerPlayTone();
      message_id = -1;
      break;

    case ID_LEDMATRIX_PRINT_PATTERN:
      ledmatrixPrintPattern();
      break;

    case ID_LEDMATRIX_PRINT_STRING:
      ledmatrixPrintString();
      break;
  }
}

//---------------------------------

void potentiometerRead() {
  int pot_value = board.potentiometer.read();

  if (pot_value == last_pot_value) return;
  last_pot_value = pot_value;

  StaticJsonBuffer<200> json_buffer;
  JsonObject& root = json_buffer.createObject();
  root["potentiometer"] = pot_value;
  root.printTo(btSerial);

  // Bluetooth is waiting "\r\n"
  btSerial.println("");
  delay(30);
}

//---------------------------------

void potentiometerScaleTo() {
  if (json.length() <= 0) return;

  StaticJsonBuffer<200> json_buffer_in;
  JsonObject& root_in = json_buffer_in.parseObject(json);

  if (!root_in.success()) {
    btSerial.println("{\"error\": \"Error parsing json message\"}");
    return;
  }

  int to_low = root_in["to_low"];
  int to_high = root_in["to_high"];

  int pot_value = board.potentiometer.scaleTo(to_low, to_high);

  if (pot_value == last_pot_value) return;
  last_pot_value = pot_value;

  StaticJsonBuffer<200> json_buffer_out;
  JsonObject& root_out = json_buffer_out.createObject();
  root_out["potentiometer"] = pot_value;
  root_out.printTo(btSerial);

  // Bluetooth is waiting "\r\n"
  btSerial.println("");
  delay(30);
}

//---------------------------------

void ldrRead() {
  int ldr_value = board.ldr.read();

  if (ldr_value == last_ldr_value) return;
  last_ldr_value = ldr_value;

  StaticJsonBuffer<200> json_buffer;
  JsonObject& root = json_buffer.createObject();
  root["ldr"] = ldr_value;
  root.printTo(btSerial);

  // Bluetooth is waiting "\r\n"
  btSerial.println("");
  delay(30);
}

//---------------------------------

void ldrScaleTo() {
  if (json.length() <= 0) return;

  StaticJsonBuffer<200> json_buffer_in;
  JsonObject& root_in = json_buffer_in.parseObject(json);

  if (!root_in.success()) {
    btSerial.println("{\"error\": \"Error parsing json message\"}");
    return;
  }

  int to_low = root_in["to_low"];
  int to_high = root_in["to_high"];

  int ldr_value = board.ldr.scaleTo(to_low, to_high);

  if (ldr_value == last_ldr_value) return;
  last_ldr_value = ldr_value;

  StaticJsonBuffer<200> json_buffer_out;
  JsonObject& root_out = json_buffer_out.createObject();
  root_out["ldr"] = ldr_value;
  root_out.printTo(btSerial);

  // Bluetooth is waiting "\r\n"
  btSerial.println("");
  delay(30);
}

//---------------------------------

void rgbOn() {
  board.rgb.on();
}

//---------------------------------

void rgbOff() {
  board.rgb.off();
}

//---------------------------------

void rgbToggle() {
  board.rgb.toggle();
}

//---------------------------------

void rgbSetColor() {
  if (json.length() <= 0) return;

  StaticJsonBuffer<200> json_buffer;
  JsonObject& root = json_buffer.parseObject(json);

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

void buzzerPlayTone() {
  if (json.length() <= 0) return;

  StaticJsonBuffer<200> json_buffer;
  JsonObject& root = json_buffer.parseObject(json);

  if (!root.success()) {
    btSerial.println("{\"error\": \"Error parsing json message\"}");
    return;
  }

  unsigned int frequency = root["frequency"];
  unsigned long duration = root["duration"];
  
  board.buzzer.playTone(frequency, duration);
}

//---------------------------------

void ledmatrixPrintPattern() {
  if (json.length() <= 0) return;
  
  StaticJsonBuffer<200> json_buffer;
  JsonObject& root = json_buffer.parseObject(json);

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

//---------------------------------

void ledmatrixPrintString() {
  if (json.length() <= 0) return;
  
  StaticJsonBuffer<200> json_buffer;
  JsonObject& root = json_buffer.parseObject(json);

  if (!root.success()) {
    btSerial.println("{\"error\": \"Error parsing json message\"}");
    return;
  }

  String text = root["text"];
  board.ledmatrix.print(text);
}

//---------------------------------
