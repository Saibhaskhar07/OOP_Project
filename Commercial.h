#ifndef COMMERCIAL_H // Header guard to prevent multiple inclusion
#define COMMERCIAL_H

#include "Accounts.h" // Include necessary header files
#include <string> // Include necessary header files

namespace bankeasy { // Begin namespace bankeasy

class Commercial : public Accounts { // Declare Commercial class inheriting from Accounts
public: // Public access specifier
    Commercial(); // Constructor
    std::string type() const override; // Override method to return account type
    void bookAppointment() const; // Method to book appointment

private: // Private access specifier
    std::string date; // Member variable for appointment date
    std::string time; // Member variable for appointment time
};

} // End namespace bankeasy

#endif // End of header guard and file
