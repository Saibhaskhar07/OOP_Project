#include "Admin.h" // Include the Admin.h file for admin related functionalities
#include <iostream>
#include <algorithm>

namespace bankeasy { // start the bankeasy namespace

Admin::Admin(const std::string& adminName, const std::string& adminEmail, const std::string& adminPassword)
    : adminName(adminName), adminEmail(adminEmail), adminPassword(adminPassword) {} // Constructor to initialize admin

std::string Admin::getAdminName() const { // Method to get admin's name
    return adminName;
}

std::string Admin::getAdminEmail() const { // Method to get admin's email
    return adminEmail; // Return admin's email
}

bool Admin::authenticate(const std::string& adminPassword) const { // Method tto aunticate admin
    return this->adminPassword == adminPassword; // Return true if passwords match
}

void Admin::viewAllUsers(const std::vector<User>& users) const { // Method to view all users
    if (users.empty()) { // Check if users vector is empty
        std::cout << "No users available.\n\n"; // Print a message
        return; // Exit the function
    }
    for (const User& user : users) { // Loop through uses vector
        std::cout << "Name: " << user.getName() << ", Email: " << user.getEmail() << ", Balance: $" << user.getBalance() << ", Account Type: " << user.getAccountType() << "\n"; // Print user details
    }
    std::cout << "\n"; // Print a newline
}

void Admin::deleteUser(std::vector<User>& users, const std::string& email) { // Method to delete a user
    auto it = std::remove_if(users.begin(), users.end(), // Create an iterattor to remove tthe user
        [&email](const User& user) {// Lambda function to compare user email
            return user.getEmail() == email; // Return true if email matches
        });
    if (it != users.end()) { //  Check if user was found
        std::cout << "Deleting user with email: " << email << "\n"; //print a message
        users.erase(it, users.end()); // Erace the user from tthe vector
        std::cout << "User deleted successfully.\n\n"; // Print a success message
    } else { // if user was found
        std::cout << "User not found.\n\n"; // Print a message
    }
}

void Admin::changeInterestRate(std::vector<User>& users, const std::string& email, double newRate) { // Method to change ineterest rate for a loan account
    for (User& user : users) { // Loop  through users vector
        if (user.getEmail() == email && user.getAccountType().find("Loan") != std::string::npos) { // Check if email matches and account type contains "Laon"
            user.changeInterestRate(newRate); // Change the interest rate
            std::cout << "Interest rate changed successfully.\n\n"; // Print a success message
            return; // Exit the function
        }
    }
    std::cout << "User not found or not a loan account.\n\n"; // Print a message
}

void Admin::freezeTransactions(std::vector<User>& users, const std::string& email) { //  Method to freeze transactions for a user
    for (User& user : users) { // Loop users vectors
        if (user.getEmail() == email) { // Check if email matches
            user.freezeTransactions(); // Freeeze transactions for the user
            std::cout << "Transactions frozen successfully.\n\n"; // Print a success message
            return; // Exit the fucntion
        }
    }
    std::cout << "User not found.\n\n"; // Print a message
}

void Admin::unfreezeTransactions(std::vector<User>& users, const std::string& email) { // Method to unfreeze transactions for a user
    for (User& user : users) { // Loop through users vector 
        if (user.getEmail() == email) { // Checdk if email matches
            user.unfreezeTransactions(); // Unfreeze transactions for the user
            std::cout << "Transactions unfrozen successfully.\n\n"; // Print a success message
            return; // Exit the function
        }
    }
    std::cout << "User not found.\n\n"; // Print a message
}

void Admin::updateLoginDetails(std::vector<User>& users, const std::string& email) { // Method to upsate login details for a user
    for (User& user : users) { // Loop through users vector
        if (user.getEmail() == email) { // Check if email matches
            std::string newEmail, newPin; // Declare variables for new email and pin 
            std::cout << "Enter new email: "; // Prompt for new email
            std::cin >> newEmail; // Read new email
            std::cout << "Enter new PIN: "; // Prompt for new PIN
            std::cin >> newPin; // Read new pin
            user.updateLoginDetails(newEmail, newPin); // Update user's login details
            std::cout << "Login details updated successfully.\n\n"; // Prints a success message
            return; // Exit the function
        }
    }
    std::cout << "User not found.\n\n"; // Print a message
}

} // end of namespace bankeasy