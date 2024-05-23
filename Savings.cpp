#include "Savings.h"

Savings::Savings(const std::string& name, double balance)
    : Personal(name, balance) {}

void Savings::displayAccountType() const {
    std::cout << "Savings Account" << std::endl;
}

void Savings::deposit(double amount) {
    if (amount > 0) {
        balance += amount + (amount * 0.01);  // Example: 1% bonus on deposits
    }
}

void Savings::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
    }
}
