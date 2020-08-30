#include "BaseConvert.h"

void BinToHex() {
}

void BaseConversion(ConversionParameters InParams)
{
	InParams.InString.erase(0, 2);

	if (InParams.ModeA == 0 && InParams.ModeB == 1) /* Binary to Decimal */
	{
	}
	else if (InParams.ModeA == 0 && InParams.ModeB == 2)  /* Binary to Hexadecimal */
	{
		std::cout << InParams.InString << " = ";
		std::bitset<32> set(InParams.InString);
		std::cout << std::hex << set.to_ullong() << std::endl;
	}
	else if (InParams.ModeA == 1 && InParams.ModeB == 0)  /* Decimal to Binary */
	{
		std::cout << InParams.InString << " = ";
		std::cout << std::bitset<8>(InParams.InString).to_string();
	}
	else if (InParams.ModeA == 1 && InParams.ModeB == 2)    /* Decimal to Hexadecimal */
	{
	}
	else if (InParams.ModeA == 2 && InParams.ModeB == 0)    /* Hexadecimal to Binary */
	{
	}
	else if (InParams.ModeA == 2 && InParams.ModeB == 1)    /* Hexadecimal to Decimal */
	{
	}
}