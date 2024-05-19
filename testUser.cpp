#include <iostream>
#include <fstream>
#include "Accounts.h"
#include "Admin.h"
#include "Personal.h"
#include "Commercial.h"

using namespace bankeasy;

void addUserInput(Accounts* accounts) {
    std::string name, email, pin, accountType;
    Loan* loan = nullptr;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << "Enter PIN: ";
    std::cin >> pin;

    if (accounts->type() == "Commercial") {
        accountType = "Commercial";
    } else {
        accountType = Personal::chooseAccountType(loan);
    }

    accounts->addUser(User(name, email, pin, accountType, loan));
}

void performUserActions(User* user) {
    int action;
    double amount;
    do {
        std::cout << "Your balance: $" << user->getBalance() << "\n";
        std::cout << "1. Deposit\n2. Withdraw\n3. Logout\nChoose an option: ";
        std::cin >> action;
        switch (action) {
            case 1:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                user->deposit(amount);
                break;
            case 2:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                user->withdraw(amount);
                break;
            case 3:
                std::cout << "Logging out...\n\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n\n";
        }
    } while (action != 3);
}

void adminActions(Admin& admin, Accounts* accounts) {
    if (accounts == nullptr) {
        std::cout << "No accounts available.\n\n";
        return;
    }
    std::vector<User>& users = accounts->getUsers();
    int choice;
    std::string email;
    do {
        std::cout << "1. View all users\n2. Delete a user\n3. Change interest rate\n4. Freeze transactions\n5. Unfreeze transactions\n6. Logout\nChoose an option: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                admin.viewAllUsers(users);
                break;
            case 2:
                std::cout << "Enter email of user to delete: ";
                std::cin >> email;
                admin.deleteUser(users, email);
                accounts->saveUsers(); // Ensure users are saved after deletion
                break;
            case 3:
                double newRate;
                std::cout << "Enter email of user to change interest rate: ";
                std::cin >> email;
                std::cout << "Enter new interest rate: ";
                std::cin >> newRate;
                admin.changeInterestRate(users, email, newRate);
                accounts->saveUsers();
                break;
            case 4:
                std::cout << "Enter email of user to freeze transactions: ";
                std::cin >> email;
                admin.freezeTransactions(users, email);
                accounts->saveUsers();
                break;
            case 5:
                std::cout << "Enter email of user to unfreeze transactions: ";
                std::cin >> email;
                admin.unfreezeTransactions(users, email);
                accounts->saveUsers();
                break;
            case 6:
                std::cout << "Logging out...\n\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n\n";
        }
    } while (choice != 6);
}

Accounts* loadAccounts() {
    std::ifstream inFile("accounts.dat");
    if (inFile.is_open() && inFile.peek() != EOF) {
        std::string accountType;
        std::getline(inFile, accountType);
        inFile.close();
        if (accountType == "Commercial") {
            return new Commercial();
        } else if (accountType == "Personal") {
            return new Personal();
        }
    }
    return nullptr;
}

int main() {
    std::cout << "Welcome to BankEasy!\n\n";

    Accounts* accounts = loadAccounts();

    Admin admin("Admin", "admin@bankeasy.com", "adminpass");
    int choice;

    do {
        std::cout << "1. Sign Up\n2. Log In\n3. Admin Login\n4. Exit\nChoose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Choose account category:\n";
                std::cout << "1. Commercial\n";
                std::cout << "2. Personal\n";
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                std::cin.ignore(); // To consume the newline character left in the input buffer

                if (choice == 1) {
                    accounts = new Commercial();
                } else if (choice == 2) {
                    accounts = new Personal();
                } else {
                    std::cout << "Invalid choice. Exiting account creation.\n\n";
                    break;
                }
                addUserInput(accounts);
                break;
            }
            case 2: {
                if (accounts == nullptr) {
                    std::cout << "No accounts created yet. Please sign up first.\n\n";
                    break;
                }
                std::string email, pin;
                std::cout << "Enter email to login: ";
                std::cin >> email;
                std::cout << "Enter PIN: ";
                std::cin >> pin;

                User* user = accounts->login(email, pin);
                if (user != nullptr) {
                    std::cout << "Welcome, " << user->getName() << "!\n";
                    std::cout << "Email: " << user->getEmail() << "\n";
                    std::cout << "Account Type: " << user->getAccountType() << "\n";
                    std::cout << "Balance: $" << user->getBalance() << "\n\n";
                    performUserActions(user);
                } else {
                    std::cout << "Login failed. Invalid email or PIN.\n\n";
                }
                break;
            }
            case 3: {
                std::string email, password;
                std::cout << "Admin Login\n";
                std::cout << "Email: ";
                std::cin >> email;
                std::cout << "Password: ";
                std::cin >> password;

                if (admin.getAdminEmail() == email && admin.authenticate(password)) {
                    std::cout << "Welcome, " << admin.getAdminName() << "!\n\n";
                    adminActions(admin, accounts);
                } else {
                    std::cout << "Invalid email or password.\n\n";
                }
                break;
            }
            case 4:
                std::cout << "Exiting...\n\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n\n";
        }
    } while (choice != 4);

    std::cout << "Thank you for banking with BankEasy!\n";
    delete accounts; // Clean up allocated memory
    return 0;
}
