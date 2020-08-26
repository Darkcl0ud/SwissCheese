#include "SwissCalc.h"


int CalculatorClass::CalculatorMain(std::istream& stream)
{
	InitializeXNmap();
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
				ProcessExpression(StreamInputCalc);
			}
		}
	} while (stream);

	return{};
};


void CalculatorClass::PrintPrev()
{
	std::cout << std::endl;

	for (size_t i = 22; i > 0 ; i--)
	{
		std::cout << "=================================================" << std::endl;
		std::cout << "x" << i-1 << ":" << std::endl;
		std::cout << PrevExpres[i-1];
		std::cout << " = " << PrevAns[i-1] << std::endl;

		if (i == 1)	/* On the last iteration */
		{
			std::cout << "=================================================" << std::endl << std::endl;
		}
	}
}


void CalculatorClass::ProcessExpression(std::string InString)
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

		for (size_t i = 21; i != 0; i--)
		{
			if (i > 0)
			{
				PrevAns[i] = PrevAns[i - 1];
				PrevAns[21] = 0;

				PrevExpres[i] = PrevExpres[i - 1];
				PrevExpres[21] = " ";
			}
		}
			
		PrevAns[0] = result;
		PrevExpres[0] = InString;
		i++;	
	}
}


void CalculatorClass::InitializeXNmap()
{
	for (size_t gi = 0; gi < 22; gi++)
	{
		std::cout << "wee" << gi;
		symbol_table.add_variable("x" + std::to_string(gi), PrevAns[gi]);
	}
}