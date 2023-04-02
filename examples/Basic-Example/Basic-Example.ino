#include <MorseDecoder.hpp>

#define pin 8

MorseDecoder morse(pin, 1, false);

void setup() {
  Serial.begin(9600);
  while(!Serial) {}
  pinMode(pin, INPUT_PULLUP);
}

void loop() {
  morse.read();
  Serial.println(morse.getData());
}