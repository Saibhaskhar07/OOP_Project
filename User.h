#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <fstream>
#include "Loan.h"

namespace bankeasy {

class User {
public:
    User(const std::string& name, const std::string& email, const std::string& pin, const std::string& accountType, Loan* loan = nullptr);
    ~User();

    std::string getName() const;
    std::string getEmail() const;
    std::string getPin() const;
    double getBalance() const;
    std::string getAccountType() const;
    void deposit(double amount);
    void withdraw(double amount);
    void save(std::ofstream& out) const;
    static User load(std::ifstream& in);
    void changeInterestRate(double newRate);
    void freezeTransactions();
    void unfreezeTransactions();

private:
    std::string name;
    std::string email;
    std::string pin;
    double balance;
    std::string accountType;
    Loan* loan;
    bool transactionsFrozen;
};

} // namespace bankeasy

#endif // USER_H
