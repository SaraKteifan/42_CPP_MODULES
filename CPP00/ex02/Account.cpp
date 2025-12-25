#include "Account.hpp"

Account::Account(int initial_deposit)
{}

Account::~Account()
{}

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
{}

int	Account::checkAmount() const
{}

void	Account::displayStatus() const
{}

void	Account::makeDeposit(int deposit)
{}

bool	Account::makeWithdrawal(int withdrawal)
{}
