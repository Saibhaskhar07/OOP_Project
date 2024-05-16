#include <iostream>
#include "Accounts.h"
using namespace std;

void addUserInput(Accounts& accounts) {
    std::string name, email, pin;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << "Enter PIN: ";
    std::cin >> pin;

    accounts.addUser(User(name, email, pin));
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
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (action != 3);
}

int main() {
    std::cout << "Welcome to BankEasy!\n";

    Accounts accounts;
    int choice;

    do {
        std::cout << "1. Sign Up\n2. Log In\n3. Exit\nChoose an option: ";
        if (!(cin>>choice)) {
            cout << "Invalid input. Please enter a valid input." << endl;
            cin.clear(); // Clear the fail state of cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input until the end of the line
            continue; // Continue to the next iteration of the loop
        };

        switch (choice) {
            case 1:
                addUserInput(accounts);
                break;
            case 2: {
                std::string email, pin;
                std::cout << "Enter email to login: ";
                std::cin >> email;
                std::cout << "Enter PIN: ";
                std::cin >> pin;

                User* user = accounts.login(email, pin);
                if (user != nullptr) {
                    std::cout << "Welcome, " << user->getName() << "!\n";
                    std::cout << "Email: " << user->getEmail() << "\n";
                    std::cout << "Balance: $" << user->getBalance() << "\n";
                    performUserActions(user);
                } else {
                    std::cout << "Login failed. Invalid email or PIN.\n";
                }
                break;
            }
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 3);

    std::cout << "Thank you for banking with BankEasy!\n";
    return 0;
}
