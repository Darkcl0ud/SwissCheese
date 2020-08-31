#pragma once

#include <sstream>
#include "Log.h"
#include "exprtk.hpp"

class Calc
{
private:

	typedef double T;
	typedef exprtk::expression<T>     expression_t;
	typedef exprtk::parser<T>             parser_t;
	typedef exprtk::symbol_table<T> symbol_table_t;
	symbol_table_t symbol_table;
	std::string expression_string;
	expression_t expression;
	parser_t parser;
	int i = 0;
	struct PreviousExpressionValues {
		double Answer = 0;
		std::string Expression;
	};
	PreviousExpressionValues PreviousVals[22];

public:
	void ProcessExpression(std::string InString);
	void PrintPrev();
	void InitializeXNmap();
};