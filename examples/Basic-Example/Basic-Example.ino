#include <MorseDecoder.h>

MorseDecoder morse(8, 20);

void setup() {
  Serial.begin(9600);
  pinMode(13, INPUT_PULLUP);
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