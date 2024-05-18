#ifndef PERSONAL_H
#define PERSONAL_H

#include <string>
#include <iostream>
#include "Accounts.h"
#include "Loan.h"

class Personal : public Accounts {
public:
    Personal();
    std::string type() const override;
    static std::string chooseAccountType(Loan*& loan);
};

#endif // PERSONAL_H
