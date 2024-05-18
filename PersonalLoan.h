#ifndef PERSONAL_LOAN_H
#define PERSONAL_LOAN_H

#include "Loan.h"

class PersonalLoan : public Loan {
public:
    PersonalLoan(double amount, int tenure);
    void showDocumentation() const override;
};

#endif // PERSONAL_LOAN_H
