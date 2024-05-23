#ifndef ACCOUNTS_H // Header guard to prevent multiple inclusions
#define ACCOUNTS_H

#include <vector>
#include <string>
#include "User.h"

namespace bankeasy { // Start the bankeasy namespace

class Accounts {//Declare the account class
public:
    Accounts(); // Constructor to initialice the Accounts object
    virtual ~Accounts(); // Virtual destructor for proper cleanup
    void addUser(const User& user); // Method to add a user to the accountsw
    User* login(const std::string& email, const std::string& pin); // Method to log in a user
    std::vector<User>& getUsers(); // Method to get lists
    virtual std::string type() const = 0; // Pure virtual function
    void saveUsers(); // To save user data to file
    void deleteUser(const std::string& email); // To delete a user

private:
    std::vector<User> users; //  Vector to store user objects
    void loadUsers(); // Method to load user data from a file
};

} // namespace bankeasy

#endif // ACCOUNTS_H