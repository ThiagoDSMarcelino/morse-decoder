#include "MorseDecoder.h"

/*!
 *  @brief Instantiates a new Morse class
 *  @param pin
 *      Set pin to get data
 *  @param wpm
 *      Words per minutes you can click
 */
MorseDecoder::MorseDecoder(uint8_t pin, int wpm = DEFAULT_WPM)
{
    _pin = pin;
    _currentState = digitalRead(_pin);
    this->setWpm(wpm);
    this->clear();
}

/*!
 *  @brief Get the defined words per minute
 */
int MorseDecoder::getWpm()
{
    return _wpm;
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
    for (int i = 0; i < DATA_LENGTH; i++)
        _data[i] = '\0';
    
    _index = 0;
}

void MorseDecoder::read()
{
    if (_index > DATA_LENGTH - 1)
        this->clear();
    
    if (_wordIndex > 4)
    {
        
    }
    bool buttonState = digitalRead(_pin);

    if (buttonState == _currentState)
        return;

    unsigned long temp = millis();
    unsigned long now = temp - _last_action;
    
    _currentState = buttonState;
    
    if (now > 3 * _unit - 1 && buttonState != PRESSED_BUTTON)
    {
        _word[_wordIndex] = '-';
        _wordIndex++;
    }
    else if (now > 1 * _unit - 1 && buttonState != PRESSED_BUTTON)
    {
        _word[_wordIndex] = '.';
        _wordIndex++;
    }
    else if (now > 7 * _unit - 1 && buttonState == PRESSED_BUTTON)
    {
        _data[_wordIndex] = ' ';
        _wordIndex++;
    }

    _last_action = temp;
}

char *MorseDecoder::getData()
{
    return _data;
}

void MorseDecoder::generateWord()
{
    
}