#include "StudentLoan.h"
#include <iostream>
#include <cmath>

namespace bankeasy {

StudentLoan::StudentLoan(double amount, int tenure, const std::string& course, const std::string& placeOfStudy)
    : Loan(amount, tenure), course(course), placeOfStudy(placeOfStudy) {
    interestRate = 12.54;
}

std::string StudentLoan::getLoanType() const {
    return "Student Loan";
}

void StudentLoan::displayRequiredDocuments() const {
    std::cout << "Required documents for Student Loan:\n";
    std::cout << "- COE\n";
    std::cout << "- Proof of Identity\n";
    std::cout << "- Proof of Residence\n";
    std::cout << "- ITR for 2 years\n";
    std::cout << "- Place of Study\n\n";
}

void StudentLoan::calculateEMI() const {
    double emi;
    double r = interestRate / (12 * 100);
    emi = (amount * r * pow(1 + r, tenure)) / (pow(1 + r, tenure) - 1);
    std::cout << "EMI for the loan is: $" << emi << "\n\n";
}

} // namespace bankeasy
