#include "PersonalLoan.h" // Include header file for PersonalLoan class
#include <iostream> // Include necessary header files

namespace bankeasy { // Begin namespace bankeasy

PersonalLoan::PersonalLoan(double amount, int tenure, const std::string& purpose) // Constructor for PersonalLoan class
    : Loan(amount, tenure), purpose(purpose) { // Initialize base class and member variable
    interestRate = 7.83; // Set specific interest rate for Personal Loans
}

std::string PersonalLoan::getLoanType() const { // Method to return loan type
    return "Personal Loan"; // Return Personal Loan as loan type
}

std::string PersonalLoan::getPurpose() const { // Method to return loan purpose
    return purpose; // Return loan purpose
}

void PersonalLoan::changeInterestRate(double newRate) { // Method to change interest rate
    interestRate = newRate; // Update interest rate
}

void PersonalLoan::displayRequiredDocuments() const { // Method to display required documents
    std::cout << "- Purpose\n- Proof of Identity\n- Proof of Residence\n- ITR for 2 years\n"; // Display required documents
}

void PersonalLoan::calculateEMI() const { // Method to calculate EMI
    double emi = (amount * interestRate / 100) / tenure; // Calculate EMI
    std::cout << "EMI for the loan is: $" << emi << "\n"; // Print EMI
}

} // End namespace bankeasy
