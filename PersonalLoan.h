#ifndef PERSONALLOAN_H // Header guard to prevent multiple inclusion
#define PERSONALLOAN_H

#include "Loan.h" // Include header file for Loan class
#include <string> // Include necessary header files

namespace bankeasy { // Begin namespace bankeasy

class PersonalLoan : public Loan { // Declare PersonalLoan class as derived from Loan class
public: // Public access specifier
    PersonalLoan(double amount, int tenure, const std::string& purpose); // Constructor for PersonalLoan class
    std::string getLoanType() const override; // Override method to return loan type
    std::string getPurpose() const; // Method to return loan purpose
    void changeInterestRate(double newRate) override; // Override method to change interest rate
    void displayRequiredDocuments() const override; // Override method to display required documents
    void calculateEMI() const override; // Override method to calculate EMI

private: // Private access specifier
    std::string purpose; // Member variable for loan purpose
};

} // End namespace bankeasy

#endif // End of header guard and file
