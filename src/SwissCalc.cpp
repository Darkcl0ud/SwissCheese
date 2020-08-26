#include "SwissCalc.h"

Logger CalcLog;

int CalculatorClass::CalculatorMain(std::istream& stream)
{
	std::string StreamInputCalc;	/* Stream Input for CPPlayground main() */
	std::cout << std::endl;
	CalcLog.ConstChar("Input expression, 'help' for help.");

	do
	{
		std::cout << ">>>> ";
		if (std::getline(stream, StreamInputCalc))  /* Gets user input from stream, assign to StreamInputCalc */
		{
			if (StreamInputCalc.empty())
			{
				CalcLog.ConstChar("ERROR - input is empty, 'help' for help.");
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
				std::cout << std::endl;
				CalcLog.ConstChar("These commands are available:");
				CalcLog.ConstChar("'exit' - Exits to Main Menu.");
				CalcLog.ConstChar("'prev' - Shows previous expressions and their evaluations, mapped to xN variables.");
				std::cout << std::endl;
			}
			else	/* If we should process the string, then.... */
			{
				ProcessExpress(StreamInputCalc);
			}
		}
	} while (stream);

	return{};
};

void CalculatorClass::PrintPrev()
{
	std::cout << std::endl;

	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "=================================================" << std::endl;
		std::cout << "x" << i << ":" << std::endl;
		std::cout << PrevExpres[i];
		std::cout << " = " << PrevAns[i] << std::endl;

		if (i == 3)	/* On the last iteration */
		{
			std::cout << "=================================================" << std::endl << std::endl;
		}
	}
}

void CalculatorClass::ProcessExpress(std::string InString)
{
	expression_string = InString;
	expression.register_symbol_table(symbol_table);

	if (!parser.compile(expression_string, expression))	/* If we get an error during parsing */
	{
		CalcLog.ConstChar("ERROR - Check your expression, 'help' for help.");
		std::cout << std::endl;
	}
	else
	{
		T result = expression.value();
		std::cout << "= " << result << std::endl << std::endl;

		// if TestArray holds x
		if (i > 18) // this should be x-2
		{
			for (size_t i = 0; i < 19; i++) // this should be < x-1
			{
				PrevAns[i] = PrevAns[i + 1];
				PrevExpres[i] = PrevExpres[i + 1];
			}
			PrevAns[18] = result; // this should be x-2
			PrevExpres[18] = InString;	/* Push current expression to PastExpressions array, printed when user uses 'prev' */

			symbol_table.add_variable("x" + std::to_string(3), PrevAns[18]); // this should be x -2
		}
		else
		{
			PrevAns[i] = result;
			PrevExpres[i] = InString;	/* Push current expression to PastExpressions array, printed when user uses 'prev' */

			symbol_table.add_variable("x" + std::to_string(i), PrevAns[i]);
		}
		i++;
	}
}