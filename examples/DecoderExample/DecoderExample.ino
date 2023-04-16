#include <MorseDecoder.h>

#define pin 8

MorseDecoder decoder(pin, 1, false);

String message = "";


void setup() {
  Serial.begin(9600);
  while(!Serial) {}
  pinMode(pin, INPUT_PULLUP);
}

void loop() {
  decoder.read();

  String temp = decoder.getData();
  if (temp.compareTo(message) != 0)
  {
    message = temp;
    Serial.println(message);
  }
}