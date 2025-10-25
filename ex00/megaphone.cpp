#include <iostream>
#include <cctype>
#include <string>

int	main(int argc, const char * const argv[])
{
	std::string argument;

	if (1 == argc)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	else
	{
		for (int i = 1; argc > i; i++)
		{
			argument = argv[i];
			for (size_t j = 0; j < argument.length(); j++)
				argument[j] = std::toupper(argument[j]);
			std::cout << argument;
		}
		std::cout << std::endl;
	}
	return 0;
}
