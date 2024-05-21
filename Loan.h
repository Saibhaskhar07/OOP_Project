#ifndef LOAN_H
#define LOAN_H

#include <string>

namespace bankeasy {

class Loan {
public:
    Loan(double amount, int tenure);
    virtual ~Loan() = default;

    double getAmount() const;
    int getTenure() const;
    virtual std::string getLoanType() const = 0;
    virtual void changeInterestRate(double newRate) = 0;
    virtual void displayRequiredDocuments() const = 0;
    virtual void calculateEMI() const = 0;

protected:
    double amount;
    int tenure;
    double interestRate;
};

} // namespace bankeasy

#endif // LOAN_H
