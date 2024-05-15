#include "Accounts.h"

Accounts::Accounts() {
    // Initialize accounts or load them from a file/database
}

void Accounts::displayAccounts() {
    if (accounts.empty()) {
        std::cout << "No accounts found.\n";
        std::cout << "Options:\n";
        std::cout << "1. Create a new account\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } else {
        std::cout << "Available accounts:\n";
        for (int i = 0; i < accounts.size(); ++i) {
            std::cout << i + 1 << ". Account Number: " << accounts[i].accountNumber << ", Balance: " << accounts[i].balance << std::endl;
        }
        std::cout << "Options:\n";
        std::cout << "1. Create a new account\n";
        std::cout << "2. Select an existing account\n";
        std::cout << "3. Delete an existing account\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                selectAccount();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}

void Accounts::createAccount() {
    Account newAccount;
    std::cout << "Enter Account Type: ";
    std::cin >> newAccount.type;
    newAccount.accountNumber = generateAccountNumber();
    newAccount.balance = 0.0;
    accounts.push_back(newAccount);
    std::cout << "Account created successfully!\n";
}

void Accounts::selectAccount() {
    // Functionality to be added
    std::cout << "Selecting account...\n";
}

void Accounts::deleteAccount() {
    // Functionality to be added
    std::cout << "Deleting account...\n";
}

std::string Accounts::generateAccountNumber() const {
    // Generate a random 16-digit account number
    std::string accountNumber = "";
    srand(time(nullptr));
    for (int i = 0; i < 16; ++i) {
        accountNumber += std::to_string(rand() % 10);
    }
    return accountNumber;
}
