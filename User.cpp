#include "User.h"
#include <fstream>

UserManager::UserManager() {
    loadUsers();
}

UserManager::~UserManager() {
    saveUsers();
}

void UserManager::signUp() {
    User newUser;
    std::cout << "Enter First Name: ";
    std::cin >> newUser.firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> newUser.lastName;
    std::cout << "Enter Email: ";
    std::cin >> newUser.email;
    std::cout << "Create Password: ";
    std::cin >> newUser.password;

    // Add default accounts
    Account checkingAccount = {"Checking", 1000.0}; // Default Checking account with $1000
    Account savingsAccount = {"Savings", 5000.0};  // Default Savings account with $5000
    newUser.accounts.push_back(checkingAccount);
    newUser.accounts.push_back(savingsAccount);

    users.push_back(newUser);
    std::cout << "Account created successfully!\n";
    saveUsers();
}

bool UserManager::login() {
    std::string email, password;
    std::cout << "Enter Email: ";
    std::cin >> email;
    std::cout << "Enter Password: ";
    std::cin >> password;

    if (checkCredentials(email, password)) {
        User* user = getUserByEmail(email);
        if (user) {
            std::cout << "Login successful! Welcome back, " << user->firstName << ".\n";
            showUserMenu(*user); // Show user-specific menu after login
            return true;
        }
    } else {
        std::cout << "Invalid email or password. Please try again.\n";
    }
    return false;
}

bool UserManager::checkCredentials(const std::string& email, const std::string& password) {
    for (const auto& user : users) {
        if (user.email == email && user.password == password) {
            return true;
        }
    }
    return false;
}

User* UserManager::getUserByEmail(const std::string& email) {
    for (auto& user : users) {
        if (user.email == email) {
            return &user;
        }
    }
    return nullptr;
}

void UserManager::loadUsers() {
    std::ifstream inFile("users.dat");
    if (inFile.is_open()) {
        User user;
        while (inFile >> user.firstName >> user.lastName >> user.email >> user.password) {
            int accountCount;
            inFile >> accountCount;
            for (int i = 0; i < accountCount; ++i) {
                Account account;
                inFile >> account.accountType >> account.balance;
                user.accounts.push_back(account);
            }
            users.push_back(user);
        }
        inFile.close();
    }
}

void UserManager::saveUsers() {
    std::ofstream outFile("users.dat");
    if (outFile.is_open()) {
        for (const auto& user : users) {
            outFile << user.firstName << " " << user.lastName << " " << user.email << " " << user.password << " " << user.accounts.size() << "\n";
            for (const auto& account : user.accounts) {
                outFile << account.accountType << " " << account.balance << "\n";
            }
        }
        outFile.close();
    }
}

void UserManager::showMenu() {
    while (true) {
        std::cout << "Welcome to the Banking App\n";
        std::cout << "1. Sign Up\n";
        std::cout << "2. Log In\n";
        std::cout << "3. Exit\n";
        std::cout << "Please enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                signUp();
                break; // Continue to show menu after sign up
            case 2:
                if (login()) {
                    return; // Exit after successful login
                }
                break;
            case 3:
                std::cout << "Exiting the program.\n";
                return; // Exit the program
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void UserManager::showUserMenu(User& user) {
    while (true) {
        std::cout << "Welcome " << user.firstName << "!\n";
        std::cout << "1. View Accounts\n";
        std::cout << "2. Perform Transaction\n";
        std::cout << "3. Log Out\n";
        std::cout << "Please enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                viewAccounts(user);
                break;
            case 2:
                performTransaction(user);
                break;
            case 3:
                std::cout << "Logging out.\n";
                return; // Exit user menu
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void UserManager::viewAccounts(const User& user) {
    std::cout << "Accounts for " << user.firstName << " " << user.lastName << ":\n";
    for (const auto& account : user.accounts) {
        std::cout << "Account Type: " << account.accountType << ", Balance: $" << account.balance << "\n";
    }
}

void UserManager::performTransaction(User& user) {
    std::cout << "Select account for transaction:\n";
    for (size_t i = 0; i < user.accounts.size(); ++i) {
        std::cout << i + 1 << ". " << user.accounts[i].accountType << " (Balance: $" << user.accounts[i].balance << ")\n";
    }
    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > user.accounts.size()) {
        std::cout << "Invalid choice.\n";
        return;
    }

    Account& selectedAccount = user.accounts[choice - 1];
    std::cout << "Selected Account: " << selectedAccount.accountType << "\n";
    std::cout << "1. Deposit\n";
    std::cout << "2. Withdraw\n";
    std::cout << "Please enter your choice: ";
    int transactionChoice;
    std::cin >> transactionChoice;

    double amount;
    switch (transactionChoice) {
        case 1:
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            if (amount > 0) {
                selectedAccount.balance += amount;
                std::cout << "Deposited $" << amount << ". New balance: $" << selectedAccount.balance << "\n";
            } else {
                std::cout << "Invalid amount.\n";
            }
            break;
        case 2:
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            if (amount > 0 && amount <= selectedAccount.balance) {
                selectedAccount.balance -= amount;
                std::cout << "Withdrew $" << amount << ". New balance: $" << selectedAccount.balance << "\n";
            } else {
                std::cout << "Invalid amount or insufficient funds.\n";
            }
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
    saveUsers(); // Save changes after transaction
}
