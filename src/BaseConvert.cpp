#include "BaseConvert.h"

void BinToHex() {
}

void BaseConversion(ConversionParameters InParams)
{
	InParams.InString.erase(0, 2);

	if (InParams.ModeA == 0)  /* Binary Input */
	{
		std::cout << std::hex << (std::bitset<64> (InParams.InString)).to_ullong() << std::endl; //works
		std::cout << std::dec << (std::bitset<64> (InParams.InString)).to_ullong() << std::endl; //works
	}
	else if (InParams.ModeA == 1)  /* Decimal Input */
	{
		std::string binary = std::bitset<64>(std::stoi(InParams.InString)).to_string();
		std::cout << binary << std::endl;
		std::cout << std::hex << (std::bitset<64> (binary)).to_ullong() << std::endl; //works
	}
	else if (InParams.ModeA == 2)	/* Hexadecimal Input */
	{
	}

}