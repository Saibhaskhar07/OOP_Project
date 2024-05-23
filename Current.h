#ifndef CURRENT_H
#define CURRENT_H

#include "Personal.h"

class Current : public Personal {
public:
    Current(const std::string& name, double balance);
    void displayAccountType() const override;
    void deposit(double amount) override;
    void withdraw(double amount) override;
};

#endif // CURRENT_H
