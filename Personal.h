#ifndef PERSONAL_H
#define PERSONAL_H

#include "Accounts.h"
#include "Loan.h"
#include <string>

namespace bankeasy { // Define namespace bankeasy

class Personal : public Accounts { // Define Personal class inheriting from Accounts
public:
    Personal(); // Constructor
    std::string type() const override; // Override function to return account type
    static std::string chooseAccountType(Loan*& loan);

private:
    std::string accountType; // Account type
};

} // namespace bankeasy

#endif // PERSONAL_H
