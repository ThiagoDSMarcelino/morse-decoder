#include "MorseLib.h"

Morse::Morse(int num)
{
    wpm = num;
    // for (int i = 0; i < sizeof(morseCode)/sizeof(morseCode[0]); i++)
    // {
    //     cout << morseCode[i];
    // }
}

char Morse::getCode(int index)
{
    return morse_code[index];
}

int getWpm()
{
    return 1;
}

char morse_code[36] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
        '4', '5', '6', '7', '8', '9'
    };