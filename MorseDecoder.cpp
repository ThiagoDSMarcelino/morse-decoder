#include "MorseDecoder.h"

/*!
 *  @brief Instantiates a new Morse class
 *  @param pin
 *      Set pin to get data
 *  @param wpm
 *      Words per minutes you can click
 */
MorseDecoder::MorseDecoder(int pin, int wpm = DEFAULT_WPM)
{
    _pin = pin;
    _wpm = wpm;
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
    
    int button = digitalRead(_pin);
    
    -
    if (button == PRESSED_BUTTON && millis() - _last_action > 1 * _unit)
    {
        _last_action = millis();
        _data[_index] = '.';
        _index++;
        return;
    }

    if (button != PRESSED_BUTTON && millis() - _last_action > 7 * _unit)
    {
        _last_action = millis();
        _data[_index] = ' ';
        _index++;
    }
}

char *MorseDecoder::getData()
{
    return _data;
}