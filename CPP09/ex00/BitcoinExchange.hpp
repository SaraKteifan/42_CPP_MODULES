#ifndef	BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;
		void	fillDB();
		void	validateLine(const std::string& line);
		void	validateDate(const std::string& date);
		void	validateValue(const std::string& value);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void	run(const std::string& filename);
};

#endif
