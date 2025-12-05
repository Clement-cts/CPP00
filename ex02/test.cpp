# include "Account.hpp"
# include <vector>

int main(void) {
    std::vector<Account> accounts;

    accounts.push_back(Account(42));
    accounts.push_back(Account(54));
    accounts.push_back(Account(957));
    accounts.push_back(Account(432));
    accounts.push_back(Account(1234));
    accounts.push_back(Account(0));
    accounts.push_back(Account(754));
    accounts.push_back(Account(16576));

    Account::displayAccountsInfos();

    for (size_t i = 0; i < accounts.size(); ++i)
        accounts[i].displayStatus();
    return 0;
}
