#include "User.h"
#include <fstream>

User::User(const std::string& name, const std::string& email, const std::string& pin, const std::string& accountType)
    : name(name), email(email), pin(pin), balance(0), accountType(accountType) {}

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
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited successfully.\n\n";
    }
}

void User::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Withdrawn successfully.\n\n";
    } else {
        std::cout << "Withdrawal failed. Insufficient balance.\n\n";
    }
}

void User::save(std::ofstream& out) const {
    out << name << '\n' << email << '\n' << pin << '\n' << balance << '\n' << accountType << '\n';
}

User User::load(std::ifstream& in) {
    std::string name, email, pin, accountType;
    double balance;
    std::getline(in, name);
    std::getline(in, email);
    std::getline(in, pin);
    in >> balance;
    in.ignore();
    std::getline(in, accountType);
    User user(name, email, pin, accountType);
    user.balance = balance;
    return user;
}
