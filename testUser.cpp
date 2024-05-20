#include <iostream>
#include <fstream>
#include <limits>
#include "Accounts.h"
#include "Admin.h"
#include "Personal.h"
#include "Commercial.h"
#include "Utils.h" // Include the utility functions

using namespace bankeasy;

void addUserInput(Accounts* accounts) {
    std::string name, email, pin, accountType;
    Loan* loan = nullptr;
    std::cout << "Enter name: ";
    name = getValidatedStringInput();
    std::cout << "Enter email: ";
    email = getValidatedStringInput();
    std::cout << "Enter PIN: ";
    pin = getValidatedStringInput();

    if (accounts->type() == "Commercial") {
        accountType = "Commercial";
        accounts->addUser(User(name, email, pin, accountType));
        dynamic_cast<Commercial*>(accounts)->bookAppointment();
    } else {
        accountType = Personal::chooseAccountType(loan);
        accounts->addUser(User(name, email, pin, accountType, loan));
    }
}

void performUserActions(User* user, Accounts* accounts) {
    int action;
    double amount;
    do {
        std::cout << "Your balance: $" << user->getBalance() << "\n";
        std::cout << "1. Deposit\n2. Withdraw\n3. Schedule Payment\n4. Update Login Details\n5. Close Account\n6. Manage Cards\n7. Logout\nChoose an option: ";
        action = getValidatedIntInput();
        switch (action) {
            case 1:
                std::cout << "Enter amount to deposit: ";
                amount = getValidatedDoubleInput();
                user->deposit(amount);
                accounts->saveUsers();
                break;
            case 2:
                std::cout << "Enter amount to withdraw: ";
                amount = getValidatedDoubleInput();
                user->withdraw(amount);
                accounts->saveUsers();
                break;
            case 3: {
                std::string purpose, frequency;
                std::cout << "Enter payment purpose: ";
                purpose = getValidatedStringInput();
                std::cout << "Enter payment amount: ";
                amount = getValidatedDoubleInput();
                std::cout << "Enter payment frequency (biweekly/monthly): ";
                frequency = getValidatedStringInput();
                user->schedulePayment(purpose, amount, frequency);
                accounts->saveUsers();
                break;
            }
            case 4: {
                std::string newEmail, newPin;
                std::cout << "Enter new email: ";
                newEmail = getValidatedStringInput();
                std::cout << "Enter new PIN: ";
                newPin = getValidatedStringInput();
                user->updateLoginDetails(newEmail, newPin);
                accounts->saveUsers();
                break;
            }
            case 5:
                accounts->deleteUser(user->getEmail());
                action = 7; // Force logout after account closure
                break;
            case 6:
                user->manageCards();
                accounts->saveUsers();
                break;
            case 7:
                std::cout << "Logging out...\n\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n\n";
        }
    } while (action != 7);
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
        std::cout << "1. View all users\n2. Delete a user\n3. Change interest rate\n4. Freeze transactions\n5. Unfreeze transactions\n6. Update Login Details\n7. Change User PIN\n8. Logout\nChoose an option: ";
        choice = getValidatedIntInput();
        switch (choice) {
            case 1:
                admin.viewAllUsers(users);
                break;
            case 2:
                std::cout << "Enter email of user to delete: ";
                email = getValidatedStringInput();
                admin.deleteUser(users, email);
                accounts->saveUsers(); // Ensure users are saved after deletion
                break;
            case 3:
                double newRate;
                std::cout << "Enter email of user to change interest rate: ";
                email = getValidatedStringInput();
                std::cout << "Enter new interest rate: ";
                newRate = getValidatedDoubleInput();
                admin.changeInterestRate(users, email, newRate);
                accounts->saveUsers();
                break;
            case 4:
                std::cout << "Enter email of user to freeze transactions: ";
                email = getValidatedStringInput();
                admin.freezeTransactions(users, email);
                accounts->saveUsers();
                break;
            case 5:
                std::cout << "Enter email of user to unfreeze transactions: ";
                email = getValidatedStringInput();
                admin.unfreezeTransactions(users, email);
                accounts->saveUsers();
                break;
            case 6:
                std::cout << "Enter email of user to update login details: ";
                email = getValidatedStringInput();
                admin.updateLoginDetails(users, email);
                accounts->saveUsers();
                break;
            case 7:
                std::cout << "Enter email of user to change PIN: ";
                email = getValidatedStringInput();
                admin.changePin(users, email);
                accounts->saveUsers();
                break;
            case 8:
                std::cout << "Logging out...\n\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n\n";
        }
    } while (choice != 8);
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
        choice = getValidatedIntInput();

        switch (choice) {
            case 1: {
                std::cout << "Choose account category:\n";
                std::cout << "1. Commercial\n";
                std::cout << "2. Personal\n";
                std::cout << "Enter your choice: ";
                choice = getValidatedIntInput();

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
                email = getValidatedStringInput();
                std::cout << "Enter PIN: ";
                pin = getValidatedStringInput();

                User* user = accounts->login(email, pin);
                if (user != nullptr) {
                    std::cout << "Welcome, " << user->getName() << "!\n";
                    std::cout << "Email: " << user->getEmail() << "\n";
                    std::cout << "Account Type: " << user->getAccountType() << "\n";
                    std::cout << "Balance: $" << user->getBalance() << "\n\n";
                    performUserActions(user, accounts);
                } else {
                    std::cout << "Login failed. Invalid email or PIN.\n\n";
                }
                break;
            }
            case 3: {
                std::string email, password;
                std::cout << "Admin Login\n";
                std::cout << "Email: ";
                email = getValidatedStringInput();
                std::cout << "Password: ";
                password = getValidatedStringInput();

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
