#include "Calc.h"

void Calc::PrintPrev()
{
	std::cout << "\n";

	for (size_t i = 21; i > 0; i--)
	{
		std::cout << "=================================================\n";
		std::cout << "x" << i - 1 << ":\n";
		std::cout << PreviousVals[i - 1].Expression;
		std::cout << " = " << PreviousVals[i - 1].Answer << "\n";

		if (i == 1)	/* On the last iteration */
		{
			std::cout << "=================================================\n\n";
		}
	}
}

void Calc::ProcessExpression(std::string InString)
{
	expression_string = InString;
	expression.register_symbol_table(symbol_table);

	if (!parser.compile(expression_string, expression))	/* If we get an error during parsing */
	{
		Log("Unkown Command - 'help' for help.");
	}
	else	/* If we get no error during parsing */
	{
		T result = expression.value();
		std::cout << "= " << result << "\n\n";

		for (size_t i = 21; i != 0; i--)
		{
			if (i > 0)
			{
				PreviousVals[i] = PreviousVals[i - 1];	/* Shifts all values left */
			}
		}

		PreviousVals[0].Answer = result;
		PreviousVals[0].Expression = InString;
		i++;
	}
}

void Calc::InitializeXNmap()
{
	for (size_t gi = 0; gi < 22; gi++)
	{
		symbol_table.add_variable("x" + std::to_string(gi), PreviousVals[gi].Answer);
	}
}