#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

void	ScalarConverter::convert(const std::string& literal)
{
	char	c;
	int		i;
	float	f;
	double	result;
	char*	end;

	result = std::strtod(literal.c_str(), &end);
	if (*end == '\0' && literal.find('.') != std::string::npos)
	{
		std::cout << "char: " << static_cast<char>(result) << std::endl;
		std::cout << "int: " << static_cast<int>(result) << std::endl;
		std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(result) << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << result << std::endl;
	}
	else if (*end == '\0' && literal.find('.') == std::string::npos)
	{
		i = static_cast<int>(result);

		std::cout << "char: " << static_cast<char>(i) << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
	}
	else if (*end == 'f' && *(end + 1) == '\0')
	{
		f = static_cast<float>(result);

		std::cout << "char: " << static_cast<char>(f) << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
	}
	else if (end == literal.c_str() && literal.length() == 1)
	{
		c = *end;

		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
	}
	else
		std::cout << "Invalid Input!" << std::endl;
}