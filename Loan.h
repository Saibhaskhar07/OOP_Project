#ifndef LOAN_H
#define LOAN_H

#include <string>

class Loan {
public:
    Loan(const std::string& loanType, double amount, int tenure);
    virtual ~Loan() = default;

    virtual void showDocumentation() const = 0;
    double calculateEMI(double interestRate) const;

    std::string getLoanType() const;
    double getAmount() const;
    int getTenure() const;

protected:
    std::string loanType;
    double amount;
    int tenure;
};

#endif // LOAN_H
