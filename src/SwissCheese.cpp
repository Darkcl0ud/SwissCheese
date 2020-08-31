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
		case evHelp:
			PrintHelp();
			break;

		case evPrev:
			calc.PrintPrev();
			break;

		case evClear:
			ClearScreen();
			break;

		case evExit:
			Log("Goodbye!");
			return(0);  /* Returns out of while loop, closing program */

		default:	/* If user did not input any of the above, process for base conversion, if no conversion modes are set, treat as an expression */

			if (boost::starts_with(szInput, "0b"))
			{
				ConversionParams.ModeA = Binary;
				ConversionParams.InString = szInput;
				BaseConversion(ConversionParams);
			}
			else if (boost::starts_with(szInput, "dec"))
			{
				ConversionParams.ModeA = Decimal;
				ConversionParams.InString = szInput;
				BaseConversion(ConversionParams);
			}
			else if (boost::starts_with(szInput, "0x"))
			{
				ConversionParams.ModeA = Hexadecimal;
				ConversionParams.InString = szInput;
				BaseConversion(ConversionParams);
			}
			else
			{
				calc.ProcessExpression(szInput);
			}
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
	s_mapStringValues["calc"] = evCalculator;
	s_mapStringValues["prev"] = evPrev;
	s_mapStringValues["help"] = evHelp;
	s_mapStringValues["clear"] = evClear;
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

void BaseConversion(ConversionParameters InParams)
{
	if (InParams.ModeA == 0)  /* Binary Input */
	{
		InParams.InString.erase(0, 2);
		std::cout << "Hex: " << std::hex << (std::bitset<64>(InParams.InString)).to_ullong() << "\n";	/* Print Hex */
		std::cout << "Dec: " << std::dec << (std::bitset<64>(InParams.InString)).to_ullong() << "\n" << "\n";	/* Print Dec */
	}
	else if (InParams.ModeA == 1)  /* Decimal Input */
	{
		InParams.InString.erase(0, 3);
		std::stringstream stream;
		long long out;
		stream << std::dec << InParams.InString;
		stream >> out;
		std::cout << "Hex: " << std::hex << (std::bitset<64>(out)).to_ullong() << "\n" << "\n";	/* Print Hex */


		std::cout << std::bitset<64>(out).to_string() << "\n";
	}
	else if (InParams.ModeA == 2)	/* Hexadecimal Input */
	{
		std::stringstream stream;
		long long out;

		stream << std::hex << InParams.InString;
		stream >> out;

		std::cout << "Dec: " << out << "\n";	/* Print Dec */
		std::cout << "Bin: " << std::bitset<64>(out).to_string() << "\n" << "\n"; /* Prints Binary */
	}
}