#include "Personal.h"

Personal::Personal() : Accounts() {}

std::string Personal::type() const {
    return "Personal";
}

std::string Personal::chooseAccountType() {
    int choice;
    std::string accountType;

    std::cout << "Choose account type:\n";
    std::cout << "1. Savings\n";
    std::cout << "2. Current\n";
    std::cout << "3. Loan\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); // To consume the newline character left in the input buffer

    switch (choice) {
        case 1:
            accountType = "Savings";
            break;
        case 2: {
            std::string businessCategory;
            std::cout << "Enter your business category: ";
            std::getline(std::cin, businessCategory);
            accountType = "Current - " + businessCategory;
            break;
        }
        case 3: {
            int loanChoice;
            std::cout << "Choose loan type:\n";
            std::cout << "1. Personal Loan\n";
            std::cout << "2. Student Loan\n";
            std::cout << "Enter your choice: ";
            std::cin >> loanChoice;
            std::cin.ignore(); // To consume the newline character left in the input buffer

            if (loanChoice == 1) {
                accountType = "Loan - Personal";
            } else if (loanChoice == 2) {
                accountType = "Loan - Student";
            } else {
                accountType = "Loan";
            }
            break;
        }
        case 4:
            std::cout << "Exiting account creation.\n\n";
            exit(0);
        default:
            std::cout << "Invalid choice. Exiting account creation.\n\n";
            exit(0);
    }

    return accountType;
}
