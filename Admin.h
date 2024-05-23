#ifndef ADMIN_H // if the ADMIN_H is not defined
#define ADMIN_H // define ADMIN_H

#include <string> 
#include <vector>
#include "User.h"

namespace bankeasy { // Start the bankeasy namespace

class Admin { // Declare the Admin class
public:
    Admin(const std::string& adminName, const std::string& adminEmail, const std::string& adminPassword); // Constructor to initialize admin
    std::string getAdminName() const; // Method to get admin's name
    std::string getAdminEmail() const; // MEtthod to get admin's email
    bool authenticate(const std::string& adminPassword) const; // Method to auntheticate main
    void viewAllUsers(const std::vector<User>& users) const; // Method to view all users
    void deleteUser(std::vector<User>& users, const std::string& email); // Method to delete a user
    void changeInterestRate(std::vector<User>& users, const std::string& email, double newRate); // Method to change interest rate for a loan account
    void freezeTransactions(std::vector<User>& users, const std::string& email); // Method to freeze transactions for a user
    void unfreezeTransactions(std::vector<User>& users, const std::string& email); // Method to unfreeze transactions for a user
    void updateLoginDetails(std::vector<User>& users, const std::string& email); // Method to update login dettails for a user

private:
    std::string adminName; // Member variable to store admin's name 
    std::string adminEmail; // Member variable to store admin's email
    std::string adminPassword; // Member variable to store admin's password
};

} // end of namespace bankeasy

#endif // ADMIN_H