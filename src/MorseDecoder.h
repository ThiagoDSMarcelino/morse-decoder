#ifndef MorseDecoder_H
#define MorseDecoder_H

#include <Arduino.h>

class MorseDecoder
{
public:
	MorseDecoder(uint8_t pin, int wpm, bool defaultButton);
  void read();
	void clear();
	void setWpm(int wpm);
  String getData();
	
private:
  const String _morse[36] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.",
    "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", "-----", ".----", "..---", "...--",
    "....-", ".....", "-....", "--...", "---..", "----."
  };
  const String _ascii[36] = {
    "A", "B", "C", "D", "E", "F",
    "G", "H", "I", "J", "K", "L",
    "M", "N", "O", "P", "Q", "R",
    "S", "T", "U", "V", "W", "X",
    "Y", "Z", "0", "1", "2", "3",
    "4", "5", "6", "7", "8", "9"
  };
  int _wpm;
  float _unit;
  uint8_t _pin;
	String _data = "";
  String _word = "";
  bool _currentState;
  bool _buttonPressed;
	unsigned long _last_action = millis();
  void generateWord();
};

#endif