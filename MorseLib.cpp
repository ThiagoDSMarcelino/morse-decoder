#include "MorseLib.h"

/*!
 *  @brief Instantiates a new Morse class
 *  @param wpm
 *         Words per minutes you can click
 */
Morse::Morse(int wpm)
{
    if (wpm < 1)
        throw "Invalid value for words per minute";
    _wpm = wpm;
}

int _index = 0;

/*!
 *  @brief Get the defined words per minute
 */
int Morse::getWpm()
{
    return _wpm;
}

/*!
 *  @brief Set a new words per minute
 *  @param wpm
 *         Words per minutes you can click
 */
void Morse::setWpm(int wpm)
{
    if (wpm < 1)
        throw "Invalid value for words per minute";
    _wpm = wpm;
}

/*!
 *  @brief Reset the array of decoded words
 */
void Morse::clear()
{
    _index = 0;
}