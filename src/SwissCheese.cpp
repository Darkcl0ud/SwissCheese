#include "SwissCheese.h"


int main()
{
	InitializeStringMap();   /* Call initialization for mapping strings to enum */
	Log("**** SwissCheese Multi Tool ****");
	std::cout << "    ";
	Log("**** v003  Darkloud ****\n");
	Log("Please select an operation, 'help' for help.");

	while (1)
	{
		std::string szInput = GetCommand(std::cin, 10);      /* Calls GetInput which calls std::getline and checks input for validity in our case */

		switch (s_mapStringValues[szInput])
		{
		case Calculator:
			CallCalc();
			break;

		case Help:
			PrintHelp();
			break;

		case evStringValue3:
			std::cout << "Detected the third valid string.";
			break;

		case evExit:
			Log("Goodbye!");
			return(0);  /* Returns out of while loop, closing program */

		default:
			s_mapStringValues.erase(szInput);   /* Erases last input from map */
			std::cout << "'" << szInput
				<< "' is an invalid option, 'help' for help.\n";
			break;
		}
	}
}

void CallCalc()
{
	Calc calc;
	calc.CalculatorMain(std::cin);
}

void PrintHelp()
{
	Log("\nThis program is a collection of other smaller programs. The main purpose of this program is for me to learn C++. If you find any use in it, feel free to use it.\n");
	Log("These commands are available:");
	Log("'calc' - A calculator that stores the last expression in a xN variable.");
	Log("'exit' - Exits the program.\n");
}

void InitializeStringMap()      /* Maps string vlues to enum values */
{
	s_mapStringValues["calc"] = Calculator;
	s_mapStringValues["help"] = Help;
	s_mapStringValues["exit"] = evExit;
}

std::string GetCommand(std::istream& stream, unsigned int MaxInputSize)
{
	std::string StreamInput;

	do
	{
		std::cout << ">>>> ";
		if (std::getline(stream, StreamInput))
		{
			if (StreamInput.empty())
			{
				Log("ERROR - input is empty, try again.");
			}

			else if (StreamInput.size() > MaxInputSize)
			{
				Log("ERROR - input is too long, 'help' for help.");
			}

			else {
				std::for_each(StreamInput.begin(),
					StreamInput.end(),
					[](char& c)
					{c = ::tolower(c); });  /* Converts string to lower case */
				return StreamInput;
			}
		}
	} while (stream);

	return{};
}