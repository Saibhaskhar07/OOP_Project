#include "Accounts.h"
#include "loading.h"
#include <fstream>
#include <iostream>

namespace bankeasy { // start the bankeasy namespace

Accounts::Accounts() { // Constructor for the Accounts class
    loadUsers(); // Load user data when an object is created
}

Accounts::~Accounts() { // Destructor for the Accounts class 
    saveUsers(); // Save user data when an object is destroyed
}

void Accounts::addUser(const User& user) { // To add a user to the accounts
    users.push_back(user); // Save user data when an object is destroyed
    saveUsers(); // Save the user data
    loading l2;
    l2.print();
    std::cout << "Account created successfully.\n\n"; // Print after account is created
}

User* Accounts::login(const std::string& email, const std::string& pin) { // To log in a user
    for (User& user : users) { // Loop through the users 
        if (user.getEmail() == email && user.getPin() == pin) { // Check if email an pin match
            user.processScheduledPayments(); // Process scheduled payments for the user
            saveUsers(); // Save the updated user data
            return &user; // Return a pointer to the logged-in user
        }
    }
    return nullptr; // Return nullptr id user is not found
}

std::vector<User>& Accounts::getUsers() { // To Get the list of users
    return users; // Return vector of users
}

void Accounts::deleteUser(const std::string& email) { // Method to delete a user
    auto it = std::remove_if(users.begin(), users.end(), // Create an iterator to remove the user
        [&email](const User& user) { // Lambda function to compare user email
            return user.getEmail() == email; // Return true if email matches
        });
    if (it != users.end()) { // check if user was found
        users.erase(it, users.end()); // Erase the user from the vector 
        saveUsers(); // Save the updated user data
        std::cout << "User deleted successfully.\n\n"; // print a success messager
    } else { // if user was not found
        std::cout << "User not found.\n\n"; // print User not found
    }
}

void Accounts::loadUsers() { //Method to load user data from a file
    std::ifstream inFile("accounts.dat"); // Open the accounts data file for reading
    if (inFile.is_open()) { // Check if file opened succesfully
        std::string accountType; // Variable to store accout type
        std::getline(inFile, accountType);// Read the first line (account type)
        while (inFile.peek() != EOF) { // Loop until the end of file
            User user = User::load(inFile); // Load a user from file
            users.push_back(user); // Add to the user to the verctor
        }
        inFile.close(); // Close to the file
    }
}

void Accounts::saveUsers() { // Method to save user data to a file
    std::ofstream outFile("accounts.dat"); // Open the accounts data file for writing
    if (outFile.is_open()) { // check if file opened succesfully
        if (!users.empty()) { // CHeck if vector  is not empty
            outFile << users.front().getAccountType() << '\n'; // write account type to file
        }
        for (const User& user : users) { // Loop through the useres in the vector
            user.save(outFile); //Save each user to file
        }
        outFile.close(); // close the file
    } else { // if file failed to open
        std::cerr << "Failed to open accounts.dat for writing.\n"; // Print an error message
    }
}

} // end of namespace bankeasy