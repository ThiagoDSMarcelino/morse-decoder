#ifndef MorseLib
#define MorseLib

#include <Arduino.h>

class Morse
{
public:
	Morse(int wordsPerMinute);
	int getWpm();
	
private:
	int wpm;
	char morse_code[36];
};

#endif