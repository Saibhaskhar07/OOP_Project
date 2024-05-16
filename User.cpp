#include "User.h"
#include <fstream>

User::User(const std::string& name, const std::string& email, const std::string& pin)
    : name(name), email(email), pin(pin), balance(0) {}

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

void User::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

void User::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
}

void User::save(std::ofstream& out) const {
    out << name << '\n' << email << '\n' << pin << '\n' << balance << '\n';
}

User User::load(std::ifstream& in) {
    std::string name, email, pin;
    double balance;
    std::getline(in, name);
    std::getline(in, email);
    std::getline(in, pin);
    in >> balance;
    in.ignore();
    User user(name, email, pin);
    user.balance = balance;
    return user;
}
