#ifndef LOAN_H
#define LOAN_H

#include "Account.h"
#include <cmath>
using namespace std;

class Loan : public Account {
protected:
    string Loan_type;
    double required_amount;
    int tenure;
    double interest;
    double EMI;

public:
    void applyForLoan();
    void type(const string& p);
    double calculateMonthlyInstallments(double principal, double monthlyInterestRate, int tenureMonths);
    virtual void displayDocuments() const = 0;
    void submitDocumentation(const string& ans);

    void set_tenure(int months);
    void set_required_amount(double value);
    int get_tenure() const;
    double get_required_amount() const;
};

#endif
