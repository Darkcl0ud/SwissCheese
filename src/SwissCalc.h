#pragma once

#include <sstream>
#include "Log.h"
#include "exprtk.hpp"

class CalculatorClass
{
private:

	typedef double T; /* Numeric type (float, double, mpfr etc.) */
	typedef exprtk::symbol_table<T> symbol_table_t;
	typedef exprtk::expression<T>     expression_t;
	typedef exprtk::parser<T>             parser_t;
	std::string expression_string;
	symbol_table_t symbol_table;
	expression_t expression;
	parser_t parser;
	std::string PrevExpres[20];
	double PrevAns[20];
	int i = 0;

	void PrintPrev();
	void ProcessExpress(std::string InString);

public:
	int CalculatorMain(std::istream& stream);
};