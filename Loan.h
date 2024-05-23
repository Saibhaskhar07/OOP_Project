#ifndef LOAN_H
#define LOAN_H

#include <string>

namespace bankeasy { // start of namespace bankeasy

class Loan : public Personal{
public:
    Loan(double amount, int tenure);
    virtual ~Loan() = default; // Constructor initializes with given loan information

// Get loan information and calculate rates
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

} // end of namespace bankeasy

#endif // LOAN_H