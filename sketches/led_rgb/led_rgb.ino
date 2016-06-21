int rPin = 9;
int gPin = 10;
int bPin = 11;

void setup() {
  randomSeed(analogRead(0));
}

void loop() {
  for(int red = 0; red <= 255; red++) {
    for(int green = 0; green <= 255; green++) {
        for(int blue = 0; blue <= 255; blue++) {
          analogWrite(rPin, red);
          analogWrite(gPin, green);  
          analogWrite(bPin, blue);
          delay(10);
         }
      } 
  }
  
}
