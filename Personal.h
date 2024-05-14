#ifndef PERSONAL_H
#define PERSONAL_H

#include "Loan.h"
#include <vector>
#include <string>

// Assuming Personal is a type of Loan
class Personal : public Loan {
public:
    // Initialize Personal with a default or specific type
    Personal() : Loan("Default Loan Type") {
        // Default constructor for Personal class
    }

    // Additional methods specific to Personal
    void displayAccountDetails() const override {
        std::cout << "Personal Loan Details:\n"
                  << "Loan Type: " << Loan_type << "\n"
                  << "Owner: " << get_name() << "\n"
                  << "Age: " << get_age() << "\n"
                  << "Email: " << get_email() << "\n"
                  << "Loan Amount: $" << required_amount << "\n"
                  << "Interest Rate: " << interest << "%" << "\n"
                  << "Tenure: " << tenure << " months" << std::endl;
    }
};

#endif