#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

#include "Account.hpp"

Account::Account () {};

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account ( int initial_deposit ) {
	_displayTimestamp();
	static int nbAccounts = 0;
	_amount = initial_deposit;
	_accountIndex = nbAccounts;
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
	nbAccounts++;
	Account::_totalAmount += _amount;
	Account::_nbAccounts = nbAccounts;
};

Account::~Account () {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
};

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals() << std::endl;
};

void	Account::makeDeposit ( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	std::cout << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
};

bool	Account::makeWithdrawal ( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount;
	if (withdrawal > _amount)
		std::cout << ";withdrawal:refused" << std::endl;
	else {
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
	}
	return 1;
};

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	// std::cout << "[19920104_091532] ";
	std::time_t now = std::time(nullptr);
    std::tm *localTime = std::localtime(&now);
    std::cout << '[' << (localTime->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << localTime->tm_mday << '_'
              << std::setw(2) << std::setfill('0') << localTime->tm_hour
              << std::setw(2) << std::setfill('0') << localTime->tm_min
              << std::setw(2) << std::setfill('0') << localTime->tm_sec << "] ";
}

int		Account::checkAmount( void ) const {
	return 1;
};

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
};

int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
};

int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
};

int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
};
