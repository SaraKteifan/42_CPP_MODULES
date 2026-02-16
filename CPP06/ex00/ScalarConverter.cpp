#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cerrno>
#include <cctype>

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

void	print_impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	print_pseudo_literal(double res)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(res) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(res) << std::endl;
}

void	print_char(double res)
{
	if (res > std::numeric_limits<char>::max()
		|| res < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else
	{
		char	c = static_cast<char>(res);
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}

void	print_int(double res)
{
	if (res > std::numeric_limits<int>::max()
		|| res < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(res) << std::endl;
}

void	print_float(double res)
{
	if (res > std::numeric_limits<float>::max() 
		|| res < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(res) << "f" << std::endl;
}

void	print_double(double res)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(res) << std::endl;
}

void	ScalarConverter::convert(const std::string& literal)
{
	double	res;
	char*	end = NULL;

	if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
		res = literal[0];
	else
	{
		errno = 0;
		res = std::strtod(literal.c_str(), &end);
	
		if (errno == ERANGE
			|| end == literal.c_str()
			|| !(*end == '\0' || (*end == 'f' && *(end + 1) == '\0')))
		{
			print_impossible();
			return ;
		}
	}

	if (std::isnan(res) || std::isinf(res))
	{
		print_pseudo_literal(res);
		return ;
	}

	print_char(res);
	print_int(res);
	print_float(res);
	print_double(res);
}