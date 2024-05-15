#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

struct Account {
    std::string accountNumber;
    double balance;
    std::string type;
};

class Accounts {
public:
    Accounts();
    void displayAccounts();
    void createAccount();
    void selectAccount();
    void deleteAccount();
private:
    std::vector<Account> accounts;
    std::string generateAccountNumber() const;
};

#endif // ACCOUNTS_H
