#ifndef MorseDecoder_H
#define MorseDecoder_H

#include <Arduino.h>

#define DATA_LENGTH 100
#define DEFAULT_WPM 50
#define PRESSED_BUTTON 0

class MorseDecoder
{
public:
	MorseDecoder(uint8_t pin, int wpm);
	int getWpm();
	void setWpm(int wpm);
	void clear();
	void read();
	char* getData();
	
private:
	int _wpm;
	int _dataIndex = 0;
	int _wordIndex = 0;
	float _unit;
	uint8_t _pin;
	bool _currentState;
	char _word[5];
	char _data[DATA_LENGTH];
	unsigned long _last_action = millis();
	void generateWord();
};

#endif