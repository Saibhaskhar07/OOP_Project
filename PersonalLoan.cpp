#include "PersonalLoan.h"
#include <iostream>
#include <cmath>

namespace bankeasy {

PersonalLoan::PersonalLoan(double amount, int tenure, const std::string& purpose)
    : Loan(amount, tenure), purpose(purpose) {
    interestRate = 7.8;
}

std::string PersonalLoan::getLoanType() const {
    return "Personal Loan";
}

void PersonalLoan::displayRequiredDocuments() const {
    std::cout << "Required documents for Personal Loan:\n";
    std::cout << "- Purpose\n";
    std::cout << "- Proof of Identity\n";
    std::cout << "- Proof of Residence\n";
    std::cout << "- ITR for 2 years\n\n";
}

void PersonalLoan::calculateEMI() const {
    double emi;
    double r = interestRate / (12 * 100);
    emi = (amount * r * pow(1 + r, tenure)) / (pow(1 + r, tenure) - 1);
    std::cout << "EMI for the loan is: $" << emi << "\n\n";
}

} // namespace bankeasy
