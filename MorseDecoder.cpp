#include "MorseDecoder.h"

/*!
 *  @brief Instantiates a new Morse class
 *  @param pin
 *      Set pin to get data
 *  @param wpm
 *      Words per minutes you can click
 */
MorseDecoder::MorseDecoder(int pin, int wpm)
{
    if (wpm < 1)
        throw "Invalid value for words per minute";

    _pin = pin;
    _wpm = wpm;
}

int _index = 0;

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
    if (wpm < 1)
        throw "Invalid value for words per minute";
    _wpm = wpm;
}

/*!
 *  @brief Reset the array of decoded words
 */
void MorseDecoder::clear()
{
    _index = 0;
}

void MorseDecoder::read()
{
    if (_index > 99)
        this->clear();
    
    if (!digitalRead(8))
    {
        _data[_index] = '.';
        _index++;
    }
}

char* MorseDecoder::getData()
{
    return _data;
}