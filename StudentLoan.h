#ifndef STUDENT_LOAN_H
#define STUDENT_LOAN_H

#include "Loan.h"

namespace bankeasy {

class StudentLoan : public Loan {
public:
    StudentLoan(double amount, int tenure);
    void showDocumentation() const override;
};

} // namespace bankeasy

#endif // STUDENT_LOAN_H
