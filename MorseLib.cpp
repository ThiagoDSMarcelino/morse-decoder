#include <iostream>
using namespace std;


class Morse {
	public:
	    Morse() {
			for (int i = 0; i < sizeof(morseCode)/sizeof(morseCode[0]); i++)
			{
				cout << morseCode[i];
			}
	    }

	private:
		char morseCode[36] = {
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
			'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
			'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3',
			'4', '5', '6', '7', '8', '9'
		};
};
