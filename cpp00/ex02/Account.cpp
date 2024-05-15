#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(0);
	std::tm *t = std::localtime(&now);

	std::cout << "["
			  << std::setw(4) << std::setfill('0') << t->tm_year + 1900
			  << std::setw(2) << std::setfill('0') << t->tm_mon + 1
			  << std::setw(2) << std::setfill('0') << t->tm_mday << "_"
			  << std::setw(2) << std::setfill('0') << t->tm_hour
			  << std::setw(2) << std::setfill('0') << t->tm_min
			  << std::setw(2) << std::setfill('0') << t->tm_sec
			  << "] ";
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals()
			  << std::endl;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount
			  << ";deposit:" << deposit;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount
			  << ";withdrawal:";
	if (withdrawal > checkAmount())
		return (std::cout << "refused" << std::endl, 0);
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal
			  << ";amount:" << this->_amount
			  << ";nb_withdrawals:" << this->_nbAccounts
			  << std::endl;
	return 1;
}
