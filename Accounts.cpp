#include "Accounts.h" // Include the Accounts header file
#include <fstream> // Include the file stream header
#include <iostream> // Include the standard input/output stream header

namespace bankeasy { // Start the bankeasy namespace

Accounts::Accounts() { // Constructor for the Accounts class
    loadUsers(); // Load user data when an object is created
}

Accounts::~Accounts() { // Destructor for the Accounts class
    saveUsers(); // Save user data when an object is destroyed
}

void Accounts::addUser(const User& user) { // Method to add a user to the accounts
    users.push_back(user); // Add the user to the vector
    saveUsers(); // Save the updated user data
    std::cout << "Account created successfully.\n\n"; // Print a success message
}

User* Accounts::login(const std::string& email, const std::string& pin) { // Method to log in a user
    for (User& user : users) { // Loop through the users
        if (user.getEmail() == email && user.getPin() == pin) { // Check if email and pin match
            user.processScheduledPayments(); // Process scheduled payments for the user
            saveUsers(); // Save the updated user data
            return &user; // Return a pointer to the logged-in user
        }
    }
    return nullptr; // Return nullptr if user is not found
}

std::vector<User>& Accounts::getUsers() { // Method to get the list of users
    return users; // Return the vector of users
}

void Accounts::deleteUser(const std::string& email) { // Method to delete a user
    auto it = std::remove_if(users.begin(), users.end(), // Create an iterator to remove the user
        [&email](const User& user) { // Lambda function to compare user email
            return user.getEmail() == email; // Return true if email matches
        });
    if (it != users.end()) { // Check if user was found
        users.erase(it, users.end()); // Erase the user from the vector
        saveUsers(); // Save the updated user data
        std::cout << "User deleted successfully.\n\n"; // Print a success message
    } else { // If user was not found
        std::cout << "User not found.\n\n"; // Print a message that user was not found
    }
}

void Accounts::loadUsers() { // Method to load user data from a file
    std::ifstream inFile("accounts.dat"); // Open the accounts data file for reading
    if (inFile.is_open()) { // Check if file opened successfully
        std::string accountType; // Variable to store account type
        std::getline(inFile, accountType); // Read the first line (account type)
        while (inFile.peek() != EOF) { // Loop until end of file
            User user = User::load(inFile); // Load a user from file
            users.push_back(user); // Add the user to the vector
        }
        inFile.close(); // Close the file
    }
}

void Accounts::saveUsers() { // Method to save user data to a file
    std::ofstream outFile("accounts.dat"); // Open the accounts data file for writing
    if (outFile.is_open()) { // Check if file opened successfully
        if (!users.empty()) { // Check if vector is not empty
            outFile << users.front().getAccountType() << '\n'; // Write account type to file
        }
        for (const User& user : users) { // Loop through users in the vector
            user.save(outFile); // Save each user to file
        }
        outFile.close(); // Close the file
    } else { // If file failed to open
        std::cerr << "Failed to open accounts.dat for writing.\n"; // Print an error message
    }
}

} // End of bankeasy namespace
