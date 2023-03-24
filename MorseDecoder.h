#ifndef MorseDecoder_H
#define MorseDecoder_H

#include <Arduino.h>

#define DATA_LENGTH 100
#define DEFAULT_WPM 50
#define PRESSED_BUTTON 0
#define SEGUND

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
	int _unit = 60/(50*_wpm);
	int _last_action = millis();
	int _pin;
	int _wpm;
	int _index = 0;
	char _data[DATA_LENGTH];
};

#endif