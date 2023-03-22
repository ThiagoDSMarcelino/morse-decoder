#include <MorseLib.h>

void setup() {
  Serial.begin(9600);
  
  Morse morse(20);

  Serial.print(morse.getWpm());
}

void loop() { }
