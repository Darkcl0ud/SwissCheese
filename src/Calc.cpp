#include "Calc.h"

int Calc::CalculatorMain(std::istream& stream)
{
	InitializeXNmap();
	std::string StreamInputCalc;	/* Stream Input for CPPlayground main() */
	Log("\nInput expression, 'help' for help.");

	do
	{
		std::cout << ">>>> ";
		if (std::getline(stream, StreamInputCalc))  /* Gets user input from stream, assign to StreamInputCalc */
		{
			if (StreamInputCalc.empty())
			{
				Log("ERROR - input is empty, 'help' for help.");
			}
			else if (StreamInputCalc == "exit")
			{
				break;
			}
			else if (StreamInputCalc == "prev")
			{
				PrintPrev();
			}
			else if (StreamInputCalc == "help")
			{
				Log("\nThese commands are available:");
				Log("'exit' - Exits to Main Menu.");
				Log("'prev' - Shows previous expressions and their evaluations, mapped to xN variables.\n");
			}
			else	/* If we should process the string, then.... */
			{
				ProcessExpression(StreamInputCalc);
			}
		}
	} while (stream);

	return{};
};

void Calc::PrintPrev()
{
	std::cout << "\n";

	for (size_t i = 22; i > 0; i--)
	{
		std::cout << "=================================================\n";
		std::cout << "x" << i - 1 << ":\n";
		std::cout << PreviousVals[i-1].Expression;
		std::cout << " = " << PreviousVals[i-1].Answer << "\n";

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
		Log("ERROR - Check your expression, 'help' for help.\n");
	}
	else	/* If we get no error during parsing */
	{
		T result = expression.value();
		std::cout << "= " << result << "\n\n";

		for (size_t i = 21; i != 0; i--)
		{
			if (i > 0)
			{
				PreviousVals[i] = PreviousVals[i - 1]; 
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