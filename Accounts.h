#ifndef ACCOUNTS_H // Header guard to prevent multiple inclusions
#define ACCOUNTS_H

#include <vector> // Include vector header for managing user data
#include <string> // Include string header for working with strings
#include "User.h" // Include User header for user-related functionalities

namespace bankeasy { // Start the bankeasy namespace

class Accounts { // Declare the Accounts class
public:
    Accounts(); // Constructor to initialize the Accounts object
    virtual ~Accounts(); // Virtual destructor for proper cleanup
    void addUser(const User& user); // Method to add a user to the accounts
    User* login(const std::string& email, const std::string& pin); // Method to log in a user
    std::vector<User>& getUsers(); // Method to get the list of users
    virtual std::string type() const = 0; // Pure virtual function to get account type
    void saveUsers(); // Method to save user data to a file
    void deleteUser(const std::string& email); // Method to delete a user

private:
    std::vector<User> users; // Vector to store user objects
    void loadUsers(); // Method to load user data from a file
};

} // End of bankeasy namespace

#endif // ACCOUNTS_H // End of header guard and file
