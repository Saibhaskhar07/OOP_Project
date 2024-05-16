#include "User.h"
#include <fstream>

User::User(const std::string& name, const std::string& email, const std::string& pin, const std::string& accountType, const std::string& extraInfo)
    : name(name), email(email), pin(pin), accountType(accountType), extraInfo(extraInfo), balance(0) {}

std::string User::getName() const {
    return name;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getPin() const {
    return pin;
}

std::string User::getAccountType() const {
    return accountType;
}

std::string User::getExtraInfo() const {
    return extraInfo;
}

double User::getBalance() const {
    return balance;
}

void User::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposit successful.\n" << std::endl;
    } else {
        std::cout << "Invalid deposit amount.\n" << std::endl;
    }
}

void User::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Withdraw successful.\n" << std::endl;
    } else {
        std::cout << "Invalid withdraw amount.\n" << std::endl;
    }
}

void User::save(std::ofstream& out) const {
    out << name << '\n' << email << '\n' << pin << '\n' << accountType << '\n' << extraInfo << '\n' << balance << '\n';
}

User User::load(std::ifstream& in) {
    std::string name, email, pin, accountType, extraInfo;
    double balance;
    std::getline(in, name);
    std::getline(in, email);
    std::getline(in, pin);
    std::getline(in, accountType);
    std::getline(in, extraInfo);
    in >> balance;
    in.ignore();
    User user(name, email, pin, accountType, extraInfo);
    user.balance = balance;
    return user;
}
