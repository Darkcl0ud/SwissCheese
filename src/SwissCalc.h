#pragma once

#include <sstream>
#include "Log.h"
#include "exprtk.hpp"

class CalculatorClass
{
private:

	typedef double T; /* Numeric type (float, double, mpfr etc.) */
	typedef exprtk::expression<T>     expression_t;
	typedef exprtk::parser<T>             parser_t;
	typedef exprtk::symbol_table<T> symbol_table_t;
	symbol_table_t symbol_table;
	std::string expression_string;
	expression_t expression;
	parser_t parser;
	std::string PrevExpres[22];
	T PrevAns[22];
	int i = 0;
	Logger CalcLog;

	void PrintPrev();
	void ProcessExpression(std::string InString);
	void InitializeXNmap();

public:
	int CalculatorMain(std::istream& stream);

};