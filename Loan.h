#ifndef LOAN_H // Header guard to prevent multiple inclusion
#define LOAN_H

#include <string> // Include necessary header files

namespace bankeasy { // Begin namespace bankeasy

class Loan { // Declare Loan class
public: // Public access specifier
    Loan(double amount, int tenure); // Constructor
    virtual ~Loan() = default; // Virtual destructor

    double getAmount() const; // Getter method for loan amount
    int getTenure() const; // Getter method for loan tenure
    virtual std::string getLoanType() const = 0; // Pure virtual method to get loan type
    virtual void changeInterestRate(double newRate) = 0; // Pure virtual method to change interest rate
    virtual void displayRequiredDocuments() const = 0; // Pure virtual method to display required documents
    virtual void calculateEMI() const = 0; // Pure virtual method to calculate EMI

protected: // Protected access specifier
    double amount; // Member variable for loan amount
    int tenure; // Member variable for loan tenure
    double interestRate; // Member variable for loan interest rate
};

} // End namespace bankeasy

#endif // End of header guard and file
