#include <MorseDecoder.h>

#define pin 8

MorseDecoder morse(pin, 1);

void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT_PULLUP);
}

void loop() {      
  char *ptr;    
  morse.read();
  ptr = morse.getData();
  for (int i = 0; i < 100; i++)
  {
    Serial.print(*(ptr+i)); Serial.print(", "); 
  }
  Serial.println("\nFim da linha");
}