class Morse
{
	public:
		Morse(int num);
		char getCode(int index);
		int getWpm();

	private:
		int wpm;
		char morse_code[36];
};