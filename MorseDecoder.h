#ifndef MorseDecoder_H
#define MorseDecoder_H

#include <Arduino.h>

class MorseDecoder
{
public:
	MorseDecoder(int pin, int wpm);
	int getWpm();
	void setWpm(int wpm);
	void clear();
	void read();
	char* getData();
private:
	int _pin;
	int _index;
	int _wpm;
	const char _morse_decoder[36] = {
		'A', 'B', 'C', 'D', 'E', 'F',
		'G', 'H', 'I', 'J', 'K', 'L',
		'M', 'N', 'O', 'P', 'Q', 'R',
		'S', 'T', 'U', 'V', 'W', 'X',
		'Y', 'Z', '0', '1', '2', '3',
		'4', '5', '6', '7', '8', '9'};
	char _data[100];
};

#endif