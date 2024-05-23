#include "Personal.h"
#include "StudentLoan.h"
#include "PersonalLoan.h"
#include <iostream>
#include "Utils.h"  // Assuming Utils.h has the validation functions

namespace bankeasy { // Define namespace bankeasy

Personal::Personal() : Accounts() {} // Constructor initializes base Accounts class

std::string Personal::type() const {
    return "Personal"; // Return Loan type
}

std::string Personal::chooseAccountType(Loan*& loan) {
    int choice;
    std::cout << "Choose account type:\n1. Savings\n2. Current\n3. Loan\n4. Exit\nEnter your choice: ";
    choice = getValidatedIntInput(); // Get a validated input
    
    if (choice == 1) { // Savings account
        return "Savings";
    } else if (choice == 2) { // Current account
        std::string businessCategory;
        std::cout << "Enter business category: ";
        businessCategory = getValidatedStringInput();
        return "Current";
    } else if (choice == 3) { // Loan account
        double amount;
        int tenure;
        std::cout << "Enter loan amount: ";
        amount = getValidatedDoubleInput();
        std::cout << "Enter loan tenure (months): ";
        tenure = getValidatedIntInput();
        std::cout << "Choose loan type:\n1. Personal Loan\n2. Student Loan\nEnter your choice: ";
        int loanChoice = getValidatedIntInput();
        if (loanChoice == 1) { // Personal Loan
            std::string purpose;
            std::cout << "Enter purpose: ";
            purpose = getValidatedStringInput();
            loan = new PersonalLoan(amount, tenure, purpose);
            loan->displayRequiredDocuments();
            loan->calculateEMI();
            return "Personal Loan";
        } else if (loanChoice == 2) { // Student Loan
            std::string course, placeOfStudy;
            std::cout << "Enter course: ";
            course = getValidatedStringInput();
            std::cout << "Enter place of study: ";
            placeOfStudy = getValidatedStringInput();
            loan = new StudentLoan(amount, tenure, course, placeOfStudy);
            loan->displayRequiredDocuments();
            loan->calculateEMI();
            return "Student Loan";
        } else { // Neither choices
            std::cout << "Invalid loan type. Exiting.\n";
            return "No Loan";
        }
    } else { // Invalid choice
        std::cout << "Invalid choice. Exiting.\n";
        return "No Loan";
    }
}

} //end of namespace bankeasy
