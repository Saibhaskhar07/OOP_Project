#ifndef PERSONAL_LOAN_H
#define PERSONAL_LOAN_H

#include "Loan.h"

namespace bankeasy {

class PersonalLoan : public Loan {
public:
    PersonalLoan(double amount, int tenure);
    void showDocumentation() const override;
};

} // namespace bankeasy

#endif // PERSONAL_LOAN_H
