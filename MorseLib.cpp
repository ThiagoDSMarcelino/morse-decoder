#include "MorseLib.h"

Morse::Morse(int wordsPerMinute)
{
    wpm = wordsPerMinute;
}

int Morse::getWpm()
{
    return wpm;
}

char morse_code[36] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9'};