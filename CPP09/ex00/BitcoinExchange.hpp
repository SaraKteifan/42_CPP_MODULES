#ifndef	BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_db;
		bool		validateDatabaseHeader(const std::string& dbHeader);
		bool		validateInputFileHeader(const std::string& fileHeader);
		bool		validateDate(const std::string& date);
		double		parseExchangeRate(const std::string& exchangeRate);
		double		parseInputValue(const std::string& stringValue, const std::string& line);
		double		findExchangeRate(const std::string& date);
		std::string	trim(const std::string& str);
		bool		isLeapYear(int year);
		bool		isThirtyDaysMonth(int month);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void	loadDatabase(const std::string& db);
		void	processInputFile(const std::string& filename);
};

#endif
