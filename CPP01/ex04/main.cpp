#include "Sed.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "You must provide 3 arguments: filename, s1, & s2" << std::endl;
		return (1);
	}

	Sed	sed(argv[1], argv[2], argv[3]);
	if (!sed.replace())
		return (1);
	return (0);
}
