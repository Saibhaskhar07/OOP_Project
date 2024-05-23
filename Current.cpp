#include "Current.h"

Current::Current(const std::string& name, double balance)
    : Personal(name, balance) {}

void Current::displayAccountType() const {
    std::cout << "Current Account" << std::endl;
}

void Current::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

void Current::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
    }
}
