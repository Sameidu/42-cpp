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
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
	nbAccounts++;
	Account::_totalAmount += _amount;
	Account::_nbAccounts = nbAccounts;
};

Account::~Account () {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
};

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
};

void	Account::makeDeposit ( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << _amount;
	_nbDeposits++;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
};

bool	Account::makeWithdrawal ( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (withdrawal > _amount)
		std::cout << ";withdrawal:refused" << std::endl;
	else {
		std::cout << ";withdrawal:" << withdrawal;
		_amount -= withdrawal;
		std::cout << ";amount:" << _amount;
		_nbWithdrawals++;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
	}
	return 1;
};

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::cout << "[19920104_091532] ";
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
