#include "Personal.h"
#include "StudentLoan.h"
#include "PersonalLoan.h"

Personal::Personal() : Accounts() {}

std::string Personal::type() const {
    return "Personal";
}

std::string Personal::chooseAccountType(Loan*& loan) {
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
            double amount;
            int tenure;
            std::cout << "Enter loan amount: ";
            std::cin >> amount;
            std::cout << "Enter loan tenure (months): ";
            std::cin >> tenure;
            std::cin.ignore(); // To consume the newline character left in the input buffer

            std::cout << "Choose loan type:\n";
            std::cout << "1. Personal Loan\n";
            std::cout << "2. Student Loan\n";
            std::cout << "Enter your choice: ";
            std::cin >> loanChoice;
            std::cin.ignore(); // To consume the newline character left in the input buffer

            if (loanChoice == 1) {
                loan = new PersonalLoan(amount, tenure);
                loan->showDocumentation();
                double emi = loan->calculateEMI(7.83);
                std::cout << "EMI for the loan is: $" << emi << "\n\n";
                accountType = loan->getLoanType();
            } else if (loanChoice == 2) {
                loan = new StudentLoan(amount, tenure);
                loan->showDocumentation();
                double emi = loan->calculateEMI(11.73);
                std::cout << "EMI for the loan is: $" << emi << "\n\n";
                accountType = loan->getLoanType();
            } else {
                std::cout << "Invalid choice. Exiting account creation.\n\n";
                exit(0);
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
