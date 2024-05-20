#include "Personal.h"
#include "Utils.h" // Include the utility functions
#include "PersonalLoan.h" // Include the PersonalLoan header
#include "StudentLoan.h" // Include the StudentLoan header

namespace bankeasy {

Personal::Personal() {}

std::string Personal::type() const {
    return "Personal";
}

std::string Personal::chooseAccountType(Loan*& loan) {
    int choice;
    std::cout << "Choose account type:\n";
    std::cout << "1. Savings\n";
    std::cout << "2. Current\n";
    std::cout << "3. Loan\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
    choice = getValidatedIntInput();

    switch (choice) {
        case 1:
            return "Savings";
        case 2: {
            std::string businessCategory;
            std::cout << "Enter your business category: ";
            businessCategory = getValidatedStringInput();
            return "Current - " + businessCategory;
        }
        case 3: {
            std::cout << "Enter loan amount: ";
            double amount = getValidatedDoubleInput();
            std::cout << "Enter loan tenure (months): ";
            int tenure = getValidatedIntInput();
            std::cout << "Choose loan type:\n";
            std::cout << "1. Personal Loan\n";
            std::cout << "2. Student Loan\n";
            std::cout << "Enter your choice: ";
            choice = getValidatedIntInput();
            if (choice == 1) {
                std::string purpose;
                std::cout << "Enter purpose of loan: ";
                purpose = getValidatedStringInput();
                loan = new PersonalLoan(amount, tenure, purpose);
                return "Personal Loan";
            } else if (choice == 2) {
                std::string course, placeOfStudy;
                std::cout << "Enter course of study: ";
                course = getValidatedStringInput();
                std::cout << "Enter place of study: ";
                placeOfStudy = getValidatedStringInput();
                loan = new StudentLoan(amount, tenure, course, placeOfStudy);
                return "Student Loan";
            } else {
                std::cout << "Invalid choice. Exiting loan application.\n\n";
                return "None";
            }
        }
        case 4:
            return "Exit";
        default:
            std::cout << "Invalid choice. Exiting account type selection.\n\n";
            return "None";
    }
}

} // namespace bankeasy
