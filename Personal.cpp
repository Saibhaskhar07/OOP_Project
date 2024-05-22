#include "Personal.h" // Include header file for Personal class
#include "StudentLoan.h" // Include header file for StudentLoan class
#include "PersonalLoan.h" // Include header file for PersonalLoan class
#include <iostream> // Include necessary header files
#include "Utils.h" // Include header file for utility functions (assuming validation functions are in Utils.h)

namespace bankeasy { // Begin namespace bankeasy

Personal::Personal() : Accounts() {} // Constructor for Personal class

std::string Personal::type() const { // Method to return account type
    return "Personal"; // Return Personal account type
}

std::string Personal::chooseAccountType(Loan*& loan) { // Method to choose account type
    int choice; // Declare variable for user choice
    std::cout << "Choose account type:\n1. Savings\n2. Current\n3. Loan\n4. Exit\nEnter your choice: "; // Prompt for account type
    choice = getValidatedIntInput(); // Get validated integer input
    
    if (choice == 1) { // If choice is Savings account
        return "Savings"; // Return Savings account type
    } else if (choice == 2) { // If choice is Current account
        std::string businessCategory; // Declare variable for business category
        std::cout << "Enter business category: "; // Prompt for business category
        businessCategory = getValidatedStringInput(); // Get validated string input
        return "Current"; // Return Current account type
    } else if (choice == 3) { // If choice is Loan
        double amount; // Declare variable for loan amount
        int tenure; // Declare variable for loan tenure
        std::cout << "Enter loan amount: "; // Prompt for loan amount
        amount = getValidatedDoubleInput(); // Get validated double input
        std::cout << "Enter loan tenure (months): "; // Prompt for loan tenure
        tenure = getValidatedIntInput(); // Get validated integer input
        std::cout << "Choose loan type:\n1. Personal Loan\n2. Student Loan\nEnter your choice: "; // Prompt for loan type choice
        int loanChoice = getValidatedIntInput(); // Get validated integer input for loan choice
        if (loanChoice == 1) { // If loan choice is Personal Loan
            std::string purpose; // Declare variable for loan purpose
            std::cout << "Enter purpose: "; // Prompt for loan purpose
            purpose = getValidatedStringInput(); // Get validated string input for purpose
            loan = new PersonalLoan(amount, tenure, purpose); // Create new PersonalLoan object
            loan->displayRequiredDocuments(); // Display required documents for loan
            loan->calculateEMI(); // Calculate EMI for loan
            return "Personal Loan"; // Return Personal Loan account type
        } else if (loanChoice == 2) { // If loan choice is Student Loan
            std::string course, placeOfStudy; // Declare variables for course and place of study
            std::cout << "Enter course: "; // Prompt for course
            course = getValidatedStringInput(); // Get validated string input for course
            std::cout << "Enter place of study: "; // Prompt for place of study
            placeOfStudy = getValidatedStringInput(); // Get validated string input for place of study
            loan = new StudentLoan(amount, tenure, course, placeOfStudy); // Create new StudentLoan object
            loan->displayRequiredDocuments(); // Display required documents for loan
            loan->calculateEMI(); // Calculate EMI for loan
            return "Student Loan"; // Return Student Loan account type
        } else { // If loan choice is invalid
            std::cout << "Invalid loan type. Exiting.\n"; // Print error message
            return "No Loan"; // Return No Loan account type
        }
    } else { // If choice is invalid
        std::cout << "Invalid choice. Exiting.\n"; // Print error message
        return "No Loan"; // Return No Loan account type
    }
}

} // End namespace bankeasy
