#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created" << std::endl;
}

Account::~Account()
{
	Account::_nbAccounts--;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed" << std::endl;
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}


void	Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:"<< _totalNbDeposits
		<<";withdrawals:" << _totalNbWithdrawals << std::endl;
}

int	Account::checkAmount() const
{
	return (this->_amount);
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int old_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
		<< ";p_amount:" << old_amount
		<< ";deposit:" << deposit
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int old_amount = this->_amount;

	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;

		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;

		Account::_displayTimestamp();
		std::cout << " index:" << this->_accountIndex
			<< ";p_amount:" << old_amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		Account::_displayTimestamp();
		std::cout << " index:" << this->_accountIndex
			<< ";p_amount:" << old_amount
			<< ";withdrawal:refused" << std::endl;
		return (false);
	}
}

void	Account::_displayTimestamp()
{
	time_t now = std::time(NULL);
	struct tm *tm_now = std::localtime(&now);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]",tm_now);
	std::cout << buffer;
}
