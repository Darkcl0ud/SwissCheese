#pragma once

#include <map>
#include <algorithm>
#include "Calc.h"
#include "BaseConvert.h"

enum StringValue {	/* Enum mapped to string values with std::map */
	evNotDefined,
	Calculator,
	Help,
	Prev,
	Clear,
	evExit
};

std::string GetCommand(std::istream& stream, unsigned int MaxInputSize);
std::map<std::string, StringValue> s_mapStringValues;    /* Map to associate the strings with the 'StringValue' enum values */
ConversionParameters ConversionParams;
bool FirstModeSet = false;
bool SecondModeSet = false;

void PrintHelp();
void InitializeStringMap();
void ClearScreen();
