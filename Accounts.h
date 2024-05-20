#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>
#include <vector>

struct Account {
    std::string accountNumber;
    double balance;
    std::string type;
};

class Accounts {
public:
    void displayAccounts();
    void createAccount(std::vector<Account>& userAccounts);
    void selectAccount();
    void deleteAccount();
    std::string generateAccountNumber() const;
};

#endif // ACCOUNTS_H
