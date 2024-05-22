#include "Loan.h" // Include header file for Loan class

namespace bankeasy { // Begin namespace bankeasy

Loan::Loan(double amount, int tenure) // Constructor for Loan class
    : amount(amount), tenure(tenure), interestRate(0.0) {} // Initialize member variables

double Loan::getAmount() const { // Method to get loan amount
    return amount; // Return loan amount
}

int Loan::getTenure() const { // Method to get loan tenure
    return tenure; // Return loan tenure
}

} // End namespace bankeasy
