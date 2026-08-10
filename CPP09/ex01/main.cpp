#include "RPN.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error\nUsage: ./RPN (mathematical_expression)" << std::endl;
		return (1);
	}

	try
	{
		RPN	rpn;
		rpn.evaluateExpression(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error\n" << e.what() << std::endl;
		return (1);
	}

	return (0);
}
