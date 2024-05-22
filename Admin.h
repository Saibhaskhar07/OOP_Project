#ifndef ADMIN_H // Header guard to prevent multiple inclusions
#define ADMIN_H

#include <string> // Include string header for working with strings
#include <vector> // Include vector header for managing user data
#include "User.h" // Include User header for user-related functionalities

namespace bankeasy { // Start the bankeasy namespace

class Admin { // Declare the Admin class
public:
    Admin(const std::string& adminName, const std::string& adminEmail, const std::string& adminPassword); // Constructor to initialize admin
    std::string getAdminName() const; // Method to get admin's name
    std::string getAdminEmail() const; // Method to get admin's email
    bool authenticate(const std::string& adminPassword) const; // Method to authenticate admin
    void viewAllUsers(const std::vector<User>& users) const; // Method to view all users
    void deleteUser(std::vector<User>& users, const std::string& email); // Method to delete a user
    void changeInterestRate(std::vector<User>& users, const std::string& email, double newRate); // Method to change interest rate for a loan account
    void freezeTransactions(std::vector<User>& users, const std::string& email); // Method to freeze transactions for a user
    void unfreezeTransactions(std::vector<User>& users, const std::string& email); // Method to unfreeze transactions for a user
    void updateLoginDetails(std::vector<User>& users, const std::string& email); // Method to update login details for a user

private:
    std::string adminName; // Member variable to store admin's name
    std::string adminEmail; // Member variable to store admin's email
    std::string adminPassword; // Member variable to store admin's password
};

} // End of bankeasy namespace

#endif // ADMIN_H // End of header guard and file
