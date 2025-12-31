#include "Harl.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "You must provide 1 argument i.e. level of these: [DEBUG, INFO, WARNING, ERROR]" << std::endl;
		return (1);
	}

	Harl	harl;
	harl.complain(argv[1]);

	return (0);
}
