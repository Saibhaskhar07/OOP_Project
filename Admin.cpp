#include "Admin.h" // Include the Admin header file for admin-related functionalities
#include <iostream> // Include the standard input/output stream header
#include <algorithm> // Include algorithm header for algorithms like remove_if

namespace bankeasy { // Start the bankeasy namespace

Admin::Admin(const std::string& adminName, const std::string& adminEmail, const std::string& adminPassword)
    : adminName(adminName), adminEmail(adminEmail), adminPassword(adminPassword) {} // Constructor to initialize admin

std::string Admin::getAdminName() const { // Method to get admin's name
    return adminName; // Return admin's name
}

std::string Admin::getAdminEmail() const { // Method to get admin's email
    return adminEmail; // Return admin's email
}

bool Admin::authenticate(const std::string& adminPassword) const { // Method to authenticate admin
    return this->adminPassword == adminPassword; // Return true if passwords match
}

void Admin::viewAllUsers(const std::vector<User>& users) const { // Method to view all users
    if (users.empty()) { // Check if users vector is empty
        std::cout << "No users available.\n\n"; // Print a message
        return; // Exit the function
    }
    for (const User& user : users) { // Loop through users vector
        std::cout << "Name: " << user.getName() << ", Email: " << user.getEmail() << ", Balance: $" << user.getBalance() << ", Account Type: " << user.getAccountType() << "\n"; // Print user details
    }
    std::cout << "\n"; // Print a newline
}

void Admin::deleteUser(std::vector<User>& users, const std::string& email) { // Method to delete a user
    auto it = std::remove_if(users.begin(), users.end(), // Create an iterator to remove the user
        [&email](const User& user) { // Lambda function to compare user email
            return user.getEmail() == email; // Return true if email matches
        });
    if (it != users.end()) { // Check if user was found
        std::cout << "Deleting user with email: " << email << "\n"; // Print a message
        users.erase(it, users.end()); // Erase the user from the vector
        std::cout << "User deleted successfully.\n\n"; // Print a success message
    } else { // If user was not found
        std::cout << "User not found.\n\n"; // Print a message
    }
}

void Admin::changeInterestRate(std::vector<User>& users, const std::string& email, double newRate) { // Method to change interest rate for a loan account
    for (User& user : users) { // Loop through users vector
        if (user.getEmail() == email && user.getAccountType().find("Loan") != std::string::npos) { // Check if email matches and account type contains "Loan"
            user.changeInterestRate(newRate); // Change the interest rate
            std::cout << "Interest rate changed successfully.\n\n"; // Print a success message
            return; // Exit the function
        }
    }
    std::cout << "User not found or not a loan account.\n\n"; // Print a message
}

void Admin::freezeTransactions(std::vector<User>& users, const std::string& email) { // Method to freeze transactions for a user
    for (User& user : users) { // Loop through users vector
        if (user.getEmail() == email) { // Check if email matches
            user.freezeTransactions(); // Freeze transactions for the user
            std::cout << "Transactions frozen successfully.\n\n"; // Print a success message
            return; // Exit the function
        }
    }
    std::cout << "User not found.\n\n"; // Print a message
}

void Admin::unfreezeTransactions(std::vector<User>& users, const std::string& email) { // Method to unfreeze transactions for a user
    for (User& user : users) { // Loop through users vector
        if (user.getEmail() == email) { // Check if email matches
            user.unfreezeTransactions(); // Unfreeze transactions for the user
            std::cout << "Transactions unfrozen successfully.\n\n"; // Print a success message
            return; // Exit the function
        }
    }
    std::cout << "User not found.\n\n"; // Print a message
}

void Admin::updateLoginDetails(std::vector<User>& users, const std::string& email) { // Method to update login details for a user
    for (User& user : users) { // Loop through users vector
        if (user.getEmail() == email) { // Check if email matches
            std::string newEmail, newPin; // Declare variables for new email and pin
            std::cout << "Enter new email: "; // Prompt for new email
            std::cin >> newEmail; // Read new email
            std::cout << "Enter new PIN: "; // Prompt for new PIN
            std::cin >> newPin; // Read new PIN
            user.updateLoginDetails(newEmail, newPin); // Update user's login details
            std::cout << "Login details updated successfully.\n\n"; // Print a success message
            return; // Exit the function
        }
    }
    std::cout << "User not found.\n\n"; // Print a message
}

} // End of bankeasy namespace
