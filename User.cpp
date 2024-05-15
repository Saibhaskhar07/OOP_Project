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

    for (auto& user : users) {
        if (user.email == email && user.password == password) {
            currentUser = &user;
            std::cout << "Login successful! Welcome back.\n";
            return true;
        }
    }
    std::cout << "Invalid email or password. Please try again.\n";
    return false;
}

void UserManager::displayUserAccounts(const User& user) {
    std::cout << "Accounts for " << user.firstName << " " << user.lastName << ":\n";
    for (const auto& account : user.accounts) {
        std::cout << "Account Number: " << account.accountNumber << ", Balance: " << account.balance << ", Type: " << account.type << std::endl;
    }
}

void UserManager::showMenu() {
    while (true) {
        std::cout << "Welcome to the Banking App\n";
        std::cout << "1. Sign Up\n";
        std::cout << "2. Log In\n";
        std::cout << "3. Display Accounts\n";
        std::cout << "4. Exit\n";
        std::cout << "Please enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                login();
                break;
            case 3:
                if (currentUser) {
                    displayUserAccounts(*currentUser);
                } else {
                    std::cout << "Please log in first.\n";
                }
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void UserManager::loadUsers() {
    std::ifstream inFile("users.dat");
    if (inFile.is_open()) {
        User user;
        while (inFile >> user.firstName >> user.lastName >> user.email >> user.password) {
            users.push_back(user);
        }
        inFile.close();
    }
}

void UserManager::saveUsers() {
    std::ofstream outFile("users.dat");
    if (outFile.is_open()) {
        for (const auto& user : users) {
            outFile << user.firstName << " " << user.lastName << " " << user.email << " " << user.password << "\n";
        }
        outFile.close();
    }
}
