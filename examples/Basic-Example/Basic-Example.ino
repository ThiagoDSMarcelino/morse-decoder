#include <MorseDecoder.h>

MorseDecoder morse(13, 20);

void setup() {
  Serial.begin(9600);
  pinMode(13, INPUT_PULLUP);
}

void loop() {          
  morse.read();
  Serial.println(morse.getData());
}