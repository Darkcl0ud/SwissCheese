#pragma once

#include <map>
#include <algorithm>
#include "Calc.h"


void CallCalc();
void PrintHelp();
void InitializeStringMap();
std::string GetCommand(std::istream& stream, unsigned int MaxInputSize);


enum StringValue {	/* Enum mapped to string values with std::map */
	evNotDefined,
	Calculator,
	Help,
	evStringValue3,
	evExit
};

static std::map<std::string, StringValue> s_mapStringValues;    /* Map to associate the strings with the 'StringValue' enum values */
char szInput[_MAX_PATH]; /* stores user input, _MAX_PATH defines maximum size */