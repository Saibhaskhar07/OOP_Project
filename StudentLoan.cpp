#include "StudentLoan.h" // Include header file for StudentLoan class
#include <iostream> // Include necessary header files

namespace bankeasy { // Begin namespace bankeasy

StudentLoan::StudentLoan(double amount, int tenure, const std::string& course, const std::string& placeOfStudy)
    : Loan(amount, tenure), course(course), placeOfStudy(placeOfStudy) {
    interestRate = 12.54; // Specific interest rate for Student Loans
}

std::string StudentLoan::getLoanType() const {
    return "Student Loan"; // Return type of loan as a string
}

std::string StudentLoan::getCourse() const {
    return course; // Return course of study
}

std::string StudentLoan::getPlaceOfStudy() const {
    return placeOfStudy; // Return place of study
}

void StudentLoan::changeInterestRate(double newRate) {
    interestRate = newRate; // Change the interest rate for student loans
}

void StudentLoan::displayRequiredDocuments() const {
    std::cout << "- COE\n" // Display required documents for student loans
              << "- Proof of Identity\n"
              << "- Proof of Residence\n"
              << "- ITR for 2 years\n"
              << "- Place of Study\n";
}

void StudentLoan::calculateEMI() const {
    double emi = (amount * interestRate / 100) / tenure; // Calculate EMI for student loans
    std::cout << "EMI for the loan is: $" << emi << "\n"; // Display calculated EMI
}

} // End namespace bankeasy
