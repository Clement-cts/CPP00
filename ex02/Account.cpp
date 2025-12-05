# include "Account.hpp"
# include <iostream>
# include <ctime>
# include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals= 0;

Account::Account(void){
}

Account::Account(int initial_deposit){
    this->_accountIndex = _nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";created" << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";amout:" << _amount
                << ";closed:" << std::endl;
}

void Account::_displayTimestamp(void) {
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);
    std::cout << '[' << (ltm->tm_year + 1900)
                << std::setw(2) << std::setfill('0') << (ltm->tm_mon + 1)
                << std::setw(2) << std::setfill('0') << ltm->tm_mday
                << '_'
                << std::setw(2) << std::setfill('0') << ltm->tm_hour
                << std::setw(2) << std::setfill('0') << ltm->tm_min
                << std::setw(2) << std::setfill('0') << ltm->tm_sec
                << "] ";
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
                << ";total:" << getTotalAmount()
                << ";deposits:" << getNbDeposits()
                << ";withdrawals:" << getNbWithdrawals()
                << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";p_amount:" << _amount
                << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits
                << std::endl;
}

bool Account::makeWithdrawal(int withdrawals) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";p_amount:" << _amount;
    if (withdrawals > _amount) {
        std::cout << ";withdrawals:refused" << std::endl;
        return false;
    }
    _amount -= withdrawals;
    _nbWithdrawals++;
    _totalAmount -= withdrawals;
    _totalNbWithdrawals++;
    std::cout << ";withdrawals:" << withdrawals
                << ";amount:" << _amount
                << ";nb_withdrawals:" << _nbWithdrawals
                << std::endl;
    return true;
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";deposits:" << _nbDeposits
                << ";withdrawals:" << _nbWithdrawals
                << std::endl;
}
