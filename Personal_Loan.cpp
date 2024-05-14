#include "Personal_Loan.h"
using namespace std;

Personal_Loan::Personal_Loan(long int p_no, int tenure, const string& purpose, double reqAmt)
: Loan(), Personal_Loan_Num(p_no), purpose(purpose) {
    set_tenure(tenure);
    set_required_amount(reqAmt);
    interest = 8.7; // Assuming a fixed interest rate for simplicity
}

void Personal_Loan::set_purpose(const string& purpose) {
    this->purpose = purpose;
}

void Personal_Loan::displayPersonal_Loan_Docs() {
    cout << "Documents required:\n";
    cout << "1. 2 Passport size photographs\n";
    cout << "2. 2 years Income Tax returns\n";
    cout << "3. 6 months Payslip\n";
    cout << "4. Proof of Identity\n";
    cout << "5. Proof of Address\n";
}

string Personal_Loan::get_purpose() const {
    return purpose;
}

double Personal_Loan::get_interest() const {
    return 8.7;
}

void Personal_Loan::displayDocuments() const {
    cout << "The details of your Personal loan are as follows:\n";
    cout << "Purpose: " << get_purpose() << endl;
    cout << "Tenure: " << get_tenure() << endl;
    cout << "Interest Rate: " << get_interest() << endl;
    cout << "Required Amount: " << get_required_amount() << endl;
}
