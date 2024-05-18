#ifndef STUDENT_LOAN_H
#define STUDENT_LOAN_H

#include "Loan.h"

class StudentLoan : public Loan {
public:
    StudentLoan(double amount, int tenure);
    void showDocumentation() const override;
};

#endif // STUDENT_LOAN_H
