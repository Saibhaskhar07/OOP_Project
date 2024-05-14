#include "Loan.h"
using namespace std;

void Loan::applyForLoan() {
    cout << "Thank you for choosing BankEasy for your Loan Application" << endl;
}

void Loan::type(const string &p) {
    cout << "Please choose: Student Loan or Personal Loan" << endl;
    cin >> Loan_type;
}

double Loan::calculateMonthlyInstallments(double principal, double monthlyInterestRate, int tenureMonths) {
    EMI = (principal * monthlyInterestRate * pow(1 + monthlyInterestRate, tenureMonths)) / (pow(1 + monthlyInterestRate, tenureMonths) - 1);
    return EMI;
}

void Loan::submitDocumentation(const string &ans) {
    cout << "Your Application has been submitted! Thanks for banking with BankEasy" << endl;
}

void Loan::set_tenure(int months) {
    tenure = months;
}

void Loan::set_required_amount(double value) {
    required_amount = value;
}

int Loan::get_tenure() const {
    return tenure;
}

double Loan::get_required_amount() const {
    return required_amount;
}
