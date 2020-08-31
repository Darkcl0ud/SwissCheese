#pragma once

#include <map>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <boost/algorithm/string/predicate.hpp>
#include "Calc.h"

enum StringValue {	/* Enum mapped to string values with std::map */
	evNotDefined,
	evCalculator,
	evHelp,
	evPrev,
	evClear,
	evExit
};

enum ConversionModes {
	Binary,
	Decimal,
	Hexadecimal
};

struct ConversionParameters {
	ConversionModes ModeA;
	std::string InString;
};

ConversionParameters ConversionParams;
std::string GetCommand(std::istream& stream, unsigned int MaxInputSize);
std::map<std::string, StringValue> s_mapStringValues;    /* Map to associate the strings with the 'StringValue' enum values */
bool FirstModeSet = false;
bool SecondModeSet = false;

void PrintHelp();
void InitializeStringMap();
void ClearScreen();
void BaseConversion(ConversionParameters InParams);
