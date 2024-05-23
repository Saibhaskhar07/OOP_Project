#ifndef BANKEASYAPP_H
#define BANKEASYAPP_H

#include <iostream>
#include <fstream>
#include "Accounts.h"
#include "Admin.h"
#include "Personal.h"
#include "Commercial.h"
#include "loading.h"
using namespace std;
using namespace bankeasy;

class BankEasyApp {
public:
    // Access to a commerical account 
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
            accounts->addUser(User(name, email, pin, accountType));
            dynamic_cast<Commercial*>(accounts)->bookAppointment();
        } else {
            accountType = Personal::chooseAccountType(loan);
            accounts->addUser(User(name, email, pin, accountType, loan));
        }
    }

    // Actions a user can perform 
    void performUserActions(User* user, Accounts* accounts) {
        int action;
        double amount;
        do {
            std::cout << "Your balance: $" << user->getBalance() << "\n";
            std::cout << "1. Deposit\n2. Withdraw\n3. Schedule Payment\n4. Update Login Details\n5. Close Account\n6. Manage Cards\n7. Logout\nChoose an option: ";
            if (!(cin >> action)) {
                cout << "Invalid input. Please enter a valid input." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (action) {
                case 1:
                    std::cout << "Enter amount to deposit: ";
                    if (!(cin >> amount)) {
                        cout << "Invalid input. Please enter a valid input." << endl;
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    user->deposit(amount);
                    accounts->saveUsers();
                    break;
                case 2:
                    std::cout << "Enter amount to withdraw: ";
                    if (!(cin >> amount)) {
                        cout << "Invalid input. Please enter a valid input." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    user->withdraw(amount);
                    accounts->saveUsers();
                    break;
                case 3: {
                    std::string purpose, frequency;
                    double amount;
                    std::cout << "Enter payment purpose: ";
                    std::cin.ignore();
                    std::getline(std::cin, purpose);
                    std::cout << "Enter payment amount: ";
                    if (!(cin >> amount)) {
                        cout << "Invalid input. Please enter a valid input." << endl;
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    std::cin.ignore();
                    std::cout << "Enter payment frequency (biweekly/monthly): ";
                    std::getline(std::cin, frequency);
                    user->schedulePayment(purpose, amount, frequency);
                    accounts->saveUsers();
                    break;
                }
                case 4: {
                    std::string newEmail, newPin;
                    std::cout << "Enter new email: ";
                    std::cin >> newEmail;
                    std::cout << "Enter new PIN: ";
                    std::cin >> newPin;
                    user->updateLoginDetails(newEmail, newPin);
                    accounts->saveUsers();
                    break;
                }
                case 5:
                    accounts->deleteUser(user->getEmail());
                    action = 7;
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

    // actions an admin can perform 
    void adminActions(Admin& admin, Accounts* accounts) {
        if (accounts == nullptr) {
            std::cout << "No accounts available.\n\n";
            return;
        }
        std::vector<User>& users = accounts->getUsers();
        int choice;
        std::string email;
        do {
            std::cout << "1. View all users\n2. Delete a user\n3. Change interest rate\n4. Freeze transactions\n5. Unfreeze transactions\n6. Update Login Details\n7. Logout\nChoose an option: ";
            if (!(cin >> choice)) {
                cout << "Invalid input. Please enter a valid input." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            switch (choice) {
                case 1:
                    admin.viewAllUsers(users);
                    break;
                case 2:
                    std::cout << "Enter email of user to delete: ";
                    std::cin >> email;
                    admin.deleteUser(users, email);
                    accounts->saveUsers();
                    break;
                case 3:
                    double newRate;
                    std::cout << "Enter email of user to change interest rate: ";
                    std::cin >> email;
                    std::cout << "Enter new interest rate: ";
                    if (!(cin >> newRate)) {
                        cout << "Invalid input. Please enter a valid input." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
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
                    std::cout << "Enter email of user to update login details: ";
                    std::cin >> email;
                    admin.updateLoginDetails(users, email);
                    accounts->saveUsers();
                    break;
                case 7:
                    std::cout << "Logging out...\n\n";
                    break;
                default:
                    std::cout << "Invalid option. Please try again.\n\n";
            }
        } while (choice != 7);
    }

    Accounts* loadAccounts() { // Load accounts and choose account typey
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

    void run() { //Executes the entire program
        std::cout << "Welcome to BankEasy!\n\n";
        loading l1;
        l1.print();
        Accounts* accounts = loadAccounts();

        Admin admin("Admin", "admin@bankeasy.com", "adminpass");
        int choice;

        do {
            std::cout << "1. Sign Up\n2. Log In\n3. Admin Login\n4. Exit\nChoose an option: ";
            if (!(cin >> choice)) {
                cout << "Invalid input. Please enter a valid input." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (choice) {
                case 1: {
                    l1.print();
                    std::cout << "Choose account category:\n";
                    std::cout << "1. Commercial\n";
                    std::cout << "2. Personal\n";
                    std::cout << "Enter your choice: ";
                    if (!(cin >> choice)) {
                        cout << "Invalid input. Please enter a valid input." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    std::cin.ignore();

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
                    l1.print();
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
                        performUserActions(user, accounts);
                    } else {
                        std::cout << "Login failed. Invalid email or PIN.\n\n";
                    }
                    break;
                }
                case 3: {
                    l1.print();
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
                    l1.print();
                    std::cout << "Exiting...\n\n";

                    break;
                default:
                    std::cout << "Invalid option. Please try again.\n\n";
            }
        } while (choice != 4);

        std::cout << "Thank you for banking with BankEasy!\n";
        delete accounts;
    }
};

#endif // BANKEASYAPP_H
