/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:51:33 by ohladkov          #+#    #+#             */
/*   Updated: 2024/03/28 10:44:58 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int Account::getTotalAmount( void ) {
	return _totalAmount;
}

int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

Account::Account ( void ) {}

// initialize atributes from class
Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts;
	if (this->_accountIndex == 8)
		this->_accountIndex = 0;
	_nbAccounts += 1;
	_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";created" << "\n";
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
	<< ";amount:" << _amount
	<< ";closed" << "\n";
	this->_accountIndex++;
	if (this->_accountIndex == 8)
		this->_accountIndex = 0;
	return ;
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
	<< ";total:"  << getTotalAmount()
	<< ";deposits:" <<  getNbDeposits()
	<< ";withdrawals:" << getNbWithdrawals() << "\n";
	// _nbAccounts
	//_totalAmount
	// _totalNbDeposits
	
}

// the function does not modify the state of the Account object on which it is called
void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
	<< ";amount:"  << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::makeDeposit( int deposit ) {
	_totalAmount += deposit;
	int n = 0;
	if (deposit)
	{
		n = 1;
		this->_nbDeposits++;
	}
	_totalNbDeposits += _nbDeposits;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
	<< ";p_amount:"  << _amount
	<< ";deposit:" << deposit
	<< ";amount:" << _amount + deposit
	<< ";nb_deposits:" << n << "\n";
	_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int n = 0;
	if (withdrawal)
		n = 1;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex
	<< ";p_amount:"  << _amount
	<< ";withdrawal:";
	if (_amount >= withdrawal) {
		// update total amount and number of withdrawals
		_nbWithdrawals++;
		_totalNbWithdrawals += _nbWithdrawals;
		_totalAmount -= withdrawal;
		std::cout << withdrawal
		<< ";amount:" << _amount - withdrawal
		<< ";nb_withdrawals:" << n << "\n";
		_amount -= withdrawal;
		return true;
	}
	else
	{
		std::cout << "refused" << "\n";
		return false;
	}
}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::_displayTimestamp( void ) {
	std::time_t now = std::time(NULL);
	std::tm* ptm = std::localtime(&now);
	char buffer[18];
	std::strftime(buffer, 18, "[%Y%m%d_%H%M%S]", ptm);
	std::cout << buffer;
}
