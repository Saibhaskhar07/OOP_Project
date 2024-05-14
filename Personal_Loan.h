#ifndef PERSONAL_LOAN_H
#define PERSONAL_LOAN_H

#include "Loan.h"
#include <vector>
#include <string>
using namespace std;

class Personal_Loan : public Loan {
protected:
    long int Personal_Loan_Num;
    string purpose;

public:
    Personal_Loan(long int p_no, int tenure, const string& purpose, double reqAmt);

    void set_purpose(const string& purpose);
    void displayPersonal_Loan_Docs();

    string get_purpose() const;
    double get_interest() const;

    void displayDocuments() const override;
};

#endif
