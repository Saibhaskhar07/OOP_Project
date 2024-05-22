#ifndef PERSONAL_H // Header guard to prevent multiple inclusion
#define PERSONAL_H

#include "Accounts.h" // Include header file for Accounts class
#include "Loan.h" // Include header file for Loan class
#include <string> // Include necessary header files

namespace bankeasy { // Begin namespace bankeasy

class Personal : public Accounts { // Declare Personal class as derived from Accounts class
public: // Public access specifier
    Personal(); // Constructor for Personal class
    std::string type() const override; // Override method to return account type
    static std::string chooseAccountType(Loan*& loan); // Static method to choose account type

private: // Private access specifier
    std::string accountType; // Member variable for account type
};

} // End namespace bankeasy

#endif // End of header guard and file
