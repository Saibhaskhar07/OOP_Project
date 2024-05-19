#ifndef LOAN_H
#define LOAN_H

#include <string>

namespace bankeasy {

class Loan {
public:
    Loan(const std::string& loanType, double amount, int tenure);
    virtual ~Loan() = default;

    virtual void showDocumentation() const = 0;
    double calculateEMI(double interestRate) const;

    std::string getLoanType() const;
    double getAmount() const;
    int getTenure() const;
    void changeInterestRate(double newRate);

protected:
    std::string loanType;
    double amount;
    int tenure;
    double interestRate;
};

} // namespace bankeasy

#endif // LOAN_H
