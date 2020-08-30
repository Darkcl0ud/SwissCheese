#include "SwissCheese.h"

int main()
{
	InitializeStringMap();	/* Call initialization for mapping strings to enum */
	Log("**** SwissCheese Multi Tool ****");
	std::cout << "    ";
	Log("**** v003  Darkloud ****\n");

	Calc calc;
	calc.InitializeXNmap();

	while (1)
	{
		std::string szInput = GetCommand(std::cin, 10);	/* Calls GetInput which calls std::getline and checks input for validity in our case */

		switch (s_mapStringValues[szInput])
		{
		case Help:
			PrintHelp();
			break;

		case Prev:
			calc.PrintPrev();
			break;

		case Clear:
			ClearScreen();
			break;

		case evExit:
			Log("Goodbye!");
			return(0);  /* Returns out of while loop, closing program */

		default:	/* If user did not input any of the above, process for base conversion, if no conversion modes are set, treat as an expression */

			if (szInput.size() >= 2)
			{
				FirstModeSet = false;
				SecondModeSet = false;

				switch (szInput.at(0))	/* Check first character of input string for Mode 1 */
				{
				case 'b':
					ConversionParams.ModeA = Binary;
					FirstModeSet = true;
					break;

				case 'd':
					ConversionParams.ModeA = Decimal;
					FirstModeSet = true;
					break;

				case 'h':
					ConversionParams.ModeA = Hexadecimal;
					FirstModeSet = true;
					break;

				default:
					break;
				}

				switch (szInput.at(1))	/* Check second character of input string for Mode 2 */
				{
				case 'b':
					ConversionParams.ModeB = Binary;
					SecondModeSet = true;
					break;

				case 'h':
					ConversionParams.ModeB = Hexadecimal;
					SecondModeSet = true;
					break;

				case 'd':
					ConversionParams.ModeB = Decimal;
					SecondModeSet = true;
					break;

				default:
					break;
				}
			}

			if (FirstModeSet && SecondModeSet)
			{
				ConversionParams.InString = szInput;
				BaseConversion(ConversionParams);
			}
			else
			{
				calc.ProcessExpression(szInput);
			}

			break;
		}
	}
}

void PrintHelp()
{
	Log("\nThis program is a collection of other smaller programs. The main purpose of this program is for me to learn C++. If you find any use in it, feel free to use it.\n");
	Log("The following commands are available, 'help 'command'' for specific module help. ");
	Log("'clear' - Clears the screen. ");
	Log("'baseconverter' - Converts between Binary, Hexadecimal, and Decimal. ");
	Log("'calc' - A calculator that stores the last expression in a xN variable. Simply type an expression to use. ");
	Log("'exit' - Exits the program.\n");
}

void InitializeStringMap()      /* Maps string vlues to enum values */
{
	s_mapStringValues["calc"] = Calculator;
	s_mapStringValues["prev"] = Prev;
	s_mapStringValues["help"] = Help;
	s_mapStringValues["clear"] = Clear;
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

void ClearScreen()
{
	std::cout << std::string(100, '\n');
}