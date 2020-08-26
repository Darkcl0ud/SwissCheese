#pragma once

#include <map>
#include <algorithm>
#include "SwissCalc.h"

void InitializeStringMap();
std::string GetInput(std::istream& stream, unsigned int MaxInputSize);
void CallCalc();

enum StringValue {	/* Enum mapped to string values with std::map */
	evNotDefined,
	Calculator,
	Help,
	evStringValue3,
	evExit
};

static std::map<std::string, StringValue> s_mapStringValues;    /* Map to associate the strings with the 'StringValue' enum values */
char szInput[_MAX_PATH]; /* stores user input, _MAX_PATH defines maximum size */