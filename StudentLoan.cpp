#include "StudentLoan.h"
#include <iostream>

namespace bankeasy { // Define namespace bankeasy

StudentLoan::StudentLoan(double amount, int tenure, const std::string& course, const std::string& placeOfStudy)
    : Loan(amount, tenure), course(course), placeOfStudy(placeOfStudy) {// Constructor initializes loan amount, tenure, course, place of study, and sets interest rate
    interestRate = 12.54; // Specific interest rate for Student Loans
}

std::string StudentLoan::getLoanType() const {
    return "Student Loan"; // Return loan type
}

// Return Student Loan information

std::string StudentLoan::getCourse() const {
    return course;
}

std::string StudentLoan::getPlaceOfStudy() const {
    return placeOfStudy;
}

void StudentLoan::changeInterestRate(double newRate) { // For changing interest rates
    interestRate = newRate;
}

void StudentLoan::displayRequiredDocuments() const { // display Loan information
    std::cout << "- COE\n- Proof of Identity\n- Proof of Residence\n- ITR for 2 years\n- Place of Study\n";
}

void StudentLoan::calculateEMI() const { // Calculate and display EMI
    double emi = (amount * interestRate / 100) / tenure;
    std::cout << "EMI for the loan is: $" << emi << "\n";
}

} // namespace bankeasy
