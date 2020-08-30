#include "BaseConvert.h"

void BinToHex() {
}

void BaseConversion(ConversionParameters InParams)
{
	InParams.InString.erase(0, 2);

	if (InParams.ModeA == 0)  /* Binary Input */
	{
		std::cout << std::hex << (std::bitset<64> (InParams.InString)).to_ullong() << std::endl;	/* Print Hex */
		std::cout << std::dec << (std::bitset<64> (InParams.InString)).to_ullong() << std::endl;	/* Print Dec */
	}
	else if (InParams.ModeA == 1)  /* Decimal Input */
	{
		long long out;
		std::stringstream stream;

		stream << std::dec << InParams.InString;
		stream >> out;

		std::cout << std::bitset<64>(out).to_string() << "\n";	/* Print Binary */
		std::cout << std::hex << (std::bitset<64> (out)).to_ullong() << std::endl;	/* Print Hex */
	}
	else if (InParams.ModeA == 2)	/* Hexadecimal Input */
	{
		long long out;
		std::stringstream stream;

		stream << std::hex << InParams.InString;
		stream >> out;

		std::cout << out << std::endl;	/* Print Dec */
		std::cout << std::bitset<64>(out).to_string(); /* Prints Binary */
	}

}