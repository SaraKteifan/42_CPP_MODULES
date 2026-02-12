#include "ScalarConverter.hpp"
#include <iostream>

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
	double	d;

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}