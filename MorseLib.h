#ifndef MorseLib
#define MorseLib

// #include <Arduino.h>

class Morse
{
public:
	Morse(int wordsPerMinute);
	int getWpm();
	void setWpm(int wordsPerMinute);
	void clear();

private:
	int _index;
	int _wpm;
	const char _morse_decoder[36] = {
		'A', 'B', 'C', 'D', 'E', 'F',
		'G', 'H', 'I', 'J', 'K', 'L',
		'M', 'N', 'O', 'P', 'Q', 'R',
		'S', 'T', 'U', 'V', 'W', 'X',
		'Y', 'Z', '0', '1', '2', '3',
		'4', '5', '6', '7', '8', '9'};
	char _code[100][5];
};

#endif