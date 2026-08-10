#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <limits>

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
		_db = other._db;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

std::string	BitcoinExchange::trim(const std::string& str)
{
	size_t	start = str.find_first_not_of(" \t\r\n");

	if (start == std::string::npos)
		return "";

	size_t	end = str.find_last_not_of(" \t\r\n");

	return (str.substr(start, end - start + 1));
}

bool	BitcoinExchange::isLeapYear(int year)
{
	if (year % 400 == 0)
		return (true);
	if (year % 100 == 0)
		return (false);

	return (year % 4 == 0);
}

bool	BitcoinExchange::isThirtyDaysMonth(int month)
{
	return (month == 4
			|| month == 6
			|| month == 9
			|| month == 11);
}

bool	BitcoinExchange::validateDatabaseHeader(const std::string& dbHeader)
{
	size_t pos = dbHeader.find(',');

	if (pos == std::string::npos)
		return (false);
	
	if (dbHeader.find(',', pos + 1) != std::string::npos)
		return (false);

	std::string first = trim(dbHeader.substr(0, pos));
	std::string second = trim(dbHeader.substr(pos + 1));

	return (first == "date" && second == "exchange_rate");
}

bool	BitcoinExchange::validateInputFileHeader(const std::string& fileHeader)
{
	size_t pos = fileHeader.find('|');

	if (pos == std::string::npos)
		return (false);
	
	if (fileHeader.find('|', pos + 1) != std::string::npos)
		return (false);

	std::string first = trim(fileHeader.substr(0, pos));
	std::string second = trim(fileHeader.substr(pos + 1));

	return (first == "date" && second == "value");
}

bool	BitcoinExchange::validateDate(const std::string& date)
{
	if (date.length() != 10)
		return (false);

	if (date[4] != '-' || date[7] != '-')
		return (false);
	
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;

		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	
	int	year = atoi(date.substr(0, 4).c_str());
	int	month = atoi(date.substr(5, 2).c_str());
	int	day = atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return (false);

	if (day < 1 || day > 31)
		return (false);

	if (month == 2)
	{
		if (isLeapYear(year))
		{
			if (day > 29)
				return (false);
		}
		else
		{
			if (day > 28)
				return (false);
		}
	}
	else if (isThirtyDaysMonth(month) && day == 31)
		return (false);

	return (true);
}

double	BitcoinExchange::parseExchangeRate(const std::string& exchangeRate)
{
	char*	end = NULL;
	errno = 0;

	double	rate = strtod(exchangeRate.c_str(), &end);

	if (end == exchangeRate.c_str())
		return (-1);

	if (*end != '\0')
		return (-1);

	if (errno == ERANGE)
		return (-1);

	if (rate < 0)
		return (-1);

	if (rate != rate 
		|| rate == std::numeric_limits<double>::infinity()
		|| rate == -std::numeric_limits<double>::infinity())
		return (-1);

	return (rate);
}

double	BitcoinExchange::parseInputValue(const std::string& stringValue, const std::string& line)
{
	char*	end = NULL;
	errno = 0;

	double	value = strtod(stringValue.c_str(), &end);

	if (end == stringValue.c_str() || *end != '\0' || value != value)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (-1);
	}

	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (-1);
	}

	if (errno == ERANGE)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (-1);
	}

	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (-1);
	}

	return (value);
}

double	BitcoinExchange::findExchangeRate(const std::string& date)
{
	std::map<std::string, double>::iterator it = _db.lower_bound(date);

	if (it != _db.end() && it->first == date)
		return (it->second);

	if (it == _db.begin())
		return (-1);

	--it;
	return (it->second);
}

void	BitcoinExchange::loadDatabase(const std::string& db)
{
	_db.clear();
	std::ifstream csvFile(db.c_str());
	if (!csvFile.is_open())
		throw std::runtime_error("Error: could not open csv file.");
	
	std::string	line;
	bool	foundHeader = false;
	while (std::getline(csvFile, line))
	{
		if (!trim(line).empty())
		{
			foundHeader = true;
			break;
		}
	}

	if (!foundHeader)
		throw std::runtime_error("Error: database is empty.");
	if (!validateDatabaseHeader(line))
		throw std::runtime_error("Error: invalid database header.");

	while (std::getline(csvFile, line))
	{
		if (trim(line).empty())
			continue;

		size_t pos = line.find(',');

		if (pos == std::string::npos || line.find(',', pos + 1) != std::string::npos)
			throw std::runtime_error("Error: invalid csv database line.");

		std::string	date = trim(line.substr(0, pos));
		std::string	exchangeRate = trim(line.substr(pos + 1));

		if (date.empty() || exchangeRate.empty())
			throw std::runtime_error("Error: missing data in database.");

		if (!validateDate(date))
			throw std::runtime_error("Error: invalid date in database.");

		double	rate = parseExchangeRate(exchangeRate);
		
		if (rate < 0)
			throw std::runtime_error("Error: invalid exchange rate value in database.");
		
		std::pair<std::map<std::string, double>::iterator, bool> result;
		result = _db.insert(std::make_pair(date, rate));

		if (!result.second)
			throw std::runtime_error("Error: duplicate date in database.");
	}
	if (_db.empty())
		throw std::runtime_error("Error: database contains no data.");
}

void	BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open input file.");
	
	std::string	line;
	bool	foundHeader = false;
	while (std::getline(inputFile, line))
	{
		if (!trim(line).empty())
		{
			foundHeader = true;
			break;
		}
	}

	if (!foundHeader)
		throw std::runtime_error("Error: input file is empty.");
	if (!validateInputFileHeader(line))
		throw std::runtime_error("Error: invalid input file header.");

	while (std::getline(inputFile, line))
	{
		if (trim(line).empty())
			continue;

		size_t pos = line.find('|');

		if (pos == std::string::npos || line.find('|', pos + 1) != std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	date = trim(line.substr(0, pos));
		std::string	stringValue = trim(line.substr(pos + 1));

		if (date.empty() || stringValue.empty())
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!validateDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		double	value = parseInputValue(stringValue, line);
		
		if (value < 0)
			continue;

		double	exchangeRate = findExchangeRate(date);

		if (exchangeRate < 0)
		{
			std::cout << "Error: no exchange rate available for this date. " << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
	}
}
