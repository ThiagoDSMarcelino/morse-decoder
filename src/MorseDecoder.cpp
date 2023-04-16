#include "MorseDecoder.h"

/*!
 *  @brief Instantiates a new Morse class
 *  @param pin
 *      Set pin to get data
 *  @param wpm
 *      Words per minutes you can click
 */
MorseDecoder::MorseDecoder(uint8_t pin, int wpm = 50, bool defaultButton = false)
{
  _pin = pin;
  _buttonPressed = !defaultButton;
  _currentState = digitalRead(_pin);
  setWpm(wpm);
}

/*!
 *  @brief Set a new words per minute
 *  @param wpm
 *         Words per minutes you can click
 */
void MorseDecoder::setWpm(int wpm)
{
  _wpm = wpm;
  _unit = 60.0f / (50.0f * wpm) * 1000;
}

/*!
 *  @brief Reset the array of decoded words
 */
void MorseDecoder::clear()
{
  _data = "";
  _word = "";
}

/*!
 *  @brief Read button
 */
void MorseDecoder::read()
{
  if (_word.length() == 5)
  {
    generateWord();
  }

  bool buttonState = digitalRead(_pin);
  if (buttonState == _currentState)
    return;
  
  unsigned long temp = millis();
  unsigned long now = temp - _last_action;
  _currentState = buttonState;

  if (now > 3 * _unit - 1 && buttonState != _buttonPressed)
  {
    _word += '-';
  }
  else if (now > 1 * _unit - 1 && buttonState != _buttonPressed)
  {
    _word += '.';
  }
  else if (now > 7 * _unit - 1 && buttonState == _buttonPressed)
  {
    _data += ' ';
    generateWord();
  }
  else if (now > 3 * _unit - 1 && buttonState == _buttonPressed)
  {
    generateWord();
  }

  _last_action = temp;
}

/*!
 *  @brief Get data stored
 */
String MorseDecoder::getData()
{
  return _data;
}

void MorseDecoder::generateWord()
{
  for (int i = 0; i < (sizeof(_morse) / sizeof(_morse[0])); i++)
  {
    if (_morse[i].compareTo(_word) == 0)
    {
      _data += _ascii[i];
      _word = "";
      return;
    }
  }

  _data += "𖡄";
  _word = "";
}
