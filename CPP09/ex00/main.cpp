#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc == 2)
	{
		BitcoinExchange	BE;
		BE.run(argv[1]);
	}
	else
		std::cout << "Error: could not open file." << std::endl;
	return (0);
}
