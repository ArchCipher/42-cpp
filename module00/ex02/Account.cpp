#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <time.h>

using std::cout;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
         << ";deposits:" << getNbDeposits()
         << ";withdrawals:" << getNbWithdrawals() << "\n";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts += 1;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account()
{
    _displayTimestamp();
    cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    cout << " index:" << _accountIndex << ";p_amount:" << _amount
         << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    cout << " index:" << _accountIndex << ";p_amount:" << _amount
         << ";withdrawal:";
    if (_amount < withdrawal)
    {
        cout << "refused\n";
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals += 1;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals += 1;
    cout << withdrawal << ";amount:" << _amount
         << ";nb_withdrawals:" << _nbWithdrawals << "\n";
    return (true);
}

int Account::checkAmount(void) const
{
    return (_totalAmount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    cout << " index:" << _accountIndex << ";amount:" << _amount
         << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
         << "\n";
}

/*
        https://en.cppreference.com/w/cpp/chrono/c/gmtime.html
        https://en.cppreference.com/w/cpp/chrono/c/localtime.html
        https://en.cppreference.com/w/cpp/io/manip.html
*/
void Account::_displayTimestamp(void)
{
    time_t rawtime = 0;
    time(&rawtime);
    struct tm *ptm = localtime(&rawtime);

    cout << "[" << ptm->tm_year + 1900 << std::setfill('0') << std::setw(2)
         << ptm->tm_mon + 1 << std::setw(2) << ptm->tm_mday << "_"
         << std::setw(2) << ptm->tm_hour << std::setw(2) << ptm->tm_min
         << std::setw(2) << ptm->tm_sec << "] ";
}
