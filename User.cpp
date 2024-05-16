#include "User.h"
#include <fstream>
#include <iostream>
using namespace std ;

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

    if (checkCredentials(email, password)) {
        std::cout << "Login successful! Welcome back.\n";
        return true;
    } else {
        std::cout << "Invalid email or password. Please try again.\n";
        return false;
    }
}

bool UserManager::checkCredentials(const std::string& email, const std::string& password) {
    for (const auto& user : users) {
        if (user.email == email && user.password == password) {
            return true;
        }
    }
    return false;
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

void UserManager::showMenu() {
    while (true) {
        std::cout << "Welcome to the Banking App\n";
        std::cout << "1. Sign Up\n";
        std::cout << "2. Log In\n";
        std::cout << "3. Exit\n";
        std::cout << "Please enter your choice: ";
        int choice;
        if (!(cin>>choice)) {
            cout << "Invalid input. Please enter a valid input." << endl;
            cin.clear(); // Clear the fail state of cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input until the end of the line
            continue; // Continue to the next iteration of the loop
        }

        switch (choice) {
            case 1:
                signUp();
                return; // Exit after sign up
            case 2:
                if (login()) {
                    return; // Exit after successful login
                }
                break;
            case 3:
                std::cout << "Exiting the program.\n";
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}