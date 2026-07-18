#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		// smth
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

void	BitcoinExchange::fillDB()
{
	std::ifstream csvFile("data.csv");
	if (!csvFile.is_open())
	{
		// Use exceptions, better
		std::cerr << "Error: could not open csv file." << std::endl;
		// return (false);
	}


}

void	validateDate(const std::string& date)
{}

void	validateValue(const std::string& value)
{}

void	BitcoinExchange::validateLine(const std::string& line)
{
	std::string	date;
	std::string	value;

	// date = line.
	size_t pos = line.find('|');

	if (pos == std::string::npos)
		throw std::runtime_error("Error: bad input");
	if (line.at(pos - 1) != ' ' || line.at(pos + 1) != ' ')
		throw std::runtime_error("Error: bad input");
	if (line.substr(0, pos - 1).empty() || line.substr(pos + 1).empty())
		throw std::runtime_error("Error: bad input");

	date = line.substr(0, pos - 1);
	value = line.substr(pos + 1);

	if (!validateDate(date))
		throw std::runtime_error("Error: bad input");
	if (!validateValue(value))
		throw std::runtime_error("Error: bad input");
}


void	BitcoinExchange::run(const std::string& filename)
{
	fillDB();
}
