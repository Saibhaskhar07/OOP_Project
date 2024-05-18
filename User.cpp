#include "User.h"
#include "StudentLoan.h"
#include "PersonalLoan.h"
#include <fstream>

namespace bankeasy {

User::User(const std::string& name, const std::string& email, const std::string& pin, const std::string& accountType, Loan* loan)
    : name(name), email(email), pin(pin), balance(loan ? loan->getAmount() : 0), accountType(accountType), loan(loan), transactionsFrozen(false) {}

User::~User() {
    delete loan;
}

std::string User::getName() const {
    return name;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getPin() const {
    return pin;
}

double User::getBalance() const {
    return balance;
}

std::string User::getAccountType() const {
    return accountType;
}

void User::deposit(double amount) {
    if (transactionsFrozen) {
        std::cout << "Transactions are frozen for this account.\n\n";
        return;
    }
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited successfully.\n\n";
    }
}

void User::withdraw(double amount) {
    if (transactionsFrozen) {
        std::cout << "Transactions are frozen for this account.\n\n";
        return;
    }
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Withdrawn successfully.\n\n";
    } else {
        std::cout << "Withdrawal failed. Insufficient balance.\n\n";
    }
}

void User::save(std::ofstream& out) const {
    out << name << '\n' << email << '\n' << pin << '\n' << balance << '\n' << accountType << '\n';
    if (loan) {
        out << loan->getLoanType() << '\n' << loan->getAmount() << '\n' << loan->getTenure() << '\n';
    } else {
        out << "No Loan\n";
    }
    out << transactionsFrozen << '\n';
}

User User::load(std::ifstream& in) {
    std::string name, email, pin, accountType, loanType;
    double balance, amount;
    int tenure;
    bool transactionsFrozen;
    std::getline(in, name);
    std::getline(in, email);
    std::getline(in, pin);
    in >> balance;
    in.ignore();
    std::getline(in, accountType);
    std::getline(in, loanType);
    if (loanType != "No Loan") {
        in >> amount >> tenure;
        in.ignore();
        Loan* loan = nullptr;
        if (loanType == "Student Loan") {
            loan = new StudentLoan(amount, tenure);
        } else if (loanType == "Personal Loan") {
            loan = new PersonalLoan(amount, tenure);
        }
        User user(name, email, pin, accountType, loan);
        user.balance = balance;
        in >> transactionsFrozen;
        user.transactionsFrozen = transactionsFrozen;
        in.ignore();
        return user;
    }
    User user(name, email, pin, accountType);
    user.balance = balance;
    in >> transactionsFrozen;
    user.transactionsFrozen = transactionsFrozen;
    in.ignore();
    return user;
}

void User::changeInterestRate(double newRate) {
    if (loan) {
        loan->changeInterestRate(newRate);
    }
}

void User::freezeTransactions() {
    transactionsFrozen = true;
}

void User::unfreezeTransactions() {
    transactionsFrozen = false;
}

} // namespace bankeasy
