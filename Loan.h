#ifndef LOAN_H
#define LOAN_H

#include "Account.h"
#include <cmath> // For pow function

class Loan : public Account {
protected:
    std::string Loan_type;
    double required_amount;
    int tenure;
    double interest;

public:
     
    // In Loan.h
    Loan(const std::string& type) : Loan_type(type), Account() { }  // Assuming Account has a default constructor

    void applyForLoan();
    double calculateMonthlyInstallments(double principal, double monthlyInterestRate, int tenureMonths);
    void submitDocumentation(const std::string& ans);

    void type(const std::string& p) override;
};

#endif
