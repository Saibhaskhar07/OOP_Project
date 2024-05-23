#ifndef SAVINGS_H
#define SAVINGS_H

#include "Personal.h"

class Savings : public Personal {
public:
    Savings(const std::string& name, double balance);
    void displayAccountType() const override;
    void deposit(double amount) override;
    void withdraw(double amount) override;
};

#endif // SAVINGS_H
