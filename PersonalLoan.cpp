#include "PersonalLoan.h"
#include <iostream>

namespace bankeasy { // Define namespace bankeasy

PersonalLoan::PersonalLoan(double amount, int tenure, const std::string& purpose)
    : Loan(amount, tenure), purpose(purpose) { // Constructor initializes loan information
    interestRate = 7.83; // Specific interest rate for Personal Loans
}

std::string PersonalLoan::getLoanType() const {
    return "Personal Loan"; // Return loan type
}

std::string PersonalLoan::getPurpose() const {
    return purpose;
}

void PersonalLoan::changeInterestRate(double newRate) {
    interestRate = newRate;
}

void PersonalLoan::displayRequiredDocuments() const {
    std::cout << "- Purpose\n- Proof of Identity\n- Proof of Residence\n- ITR for 2 years\n";
}

// Calculate and display EMI
void PersonalLoan::calculateEMI() const {
    double emi = (amount * interestRate / 100) / tenure;
    std::cout << "EMI for the loan is: $" << emi << "\n";
}

} // namespace bankeasy
