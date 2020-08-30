#pragma once

#include <iostream>
#include <string>
#include <bitset>

enum ConversionModes {
	Binary,
	Decimal,
	Hexadecimal
};

struct ConversionParameters {
	ConversionModes ModeA;
	ConversionModes ModeB;
	std::string InString;
};

void BinToHex();
void BaseConversion(ConversionParameters InParams);
