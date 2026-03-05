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

int	is_char(const std::string& literal)
{
	if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
		return (1);
	return (0);
}

void	handle_char_literal(const std::string& literal)
{
	char	c = literal[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

int	is_valid_num(const std::string& literal)
{
	int start = 0;
	if (literal[0] == '+' || literal[0] == '-')
	{
		start = 1;
		if (!(std::isdigit(static_cast<unsigned char>(literal[1]))))
			return (0);
	}
	// only digits or 'f' or '.'
	for(size_t i = start; i < literal.length(); i++)
	{
		if (!(std::isdigit(static_cast<unsigned char>(literal[i]))
			|| literal[i] == 'f'
			|| literal[i] == '.'))
			return (0);
	}
	// only 1 'f' at the end
	for(size_t i = start; i < (literal.length() - 1); i++)
	{
		if (literal[i] == 'f')
			return (0);
	}
	// only 1 '.' with digits before and after
	int	dot_count = 0;
	if (literal[start] == '.' || literal[literal.length() - 1] == '.')
		return (0);
	for(size_t i = start; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
			if (literal[i - 1] && !(std::isdigit(static_cast<unsigned char>(literal[i - 1]))))
				return (0);
			if (literal[i + 1] && !(std::isdigit(static_cast<unsigned char>(literal[i + 1]))))
				return (0);
		}
	}
	return (1);
}

void	handle_float_literal(const std::string& literal)
{
	char*	end = NULL;
	errno = 0;
	float	f = strtof(literal.c_str(), &end);
	if (errno == ERANGE)
	{
		print_impossible();
		return;
	}

	if (f > std::numeric_limits<char>::max()
		|| f < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else
	{
		char	c = static_cast<char>(f);
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	if (f > std::numeric_limits<int>::max()
		|| f < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void	handle_double_literal(const std::string& literal)
{
	char*	end = NULL;
	errno = 0;
	double	d = strtod(literal.c_str(), &end);
	if (errno == ERANGE)
	{
		print_impossible();
		return;
	}

	if (d > std::numeric_limits<char>::max()
		|| d < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else
	{
		char	c = static_cast<char>(d);
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	if (d > std::numeric_limits<int>::max()
		|| d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d > std::numeric_limits<float>::max() 
		|| d < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	handle_int_literal(const std::string& literal)
{
	char*	end = NULL;
	errno = 0;
	long	i = strtol(literal.c_str(), &end, 10);
	if (errno == ERANGE
		|| i > std::numeric_limits<int>::max()
		|| i < std::numeric_limits<int>::min())
	{
		print_impossible();
		return;
	}

	if (i > std::numeric_limits<char>::max()
		|| i < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else
	{
		char	c = static_cast<char>(i);
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void	handle_num_literal(const std::string& literal)
{
	if (literal[literal.length() - 1] == 'f')
		handle_float_literal(literal);
	else if (literal.find('.') != std::string::npos)
		handle_double_literal(literal);
	else
		handle_int_literal(literal);
}

int	is_special(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf"
		|| literal == "-inf" || literal == "-inff"
		|| literal == "+inf" || literal == "+inff")
		return (1);
	return (0);
}

void	handle_special_literal(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string& literal)
{
	if (is_char(literal))
		handle_char_literal(literal);
	else if (is_valid_num(literal))
		handle_num_literal(literal);
	else if (is_special(literal))
		handle_special_literal(literal);
	else
		print_impossible();
}
