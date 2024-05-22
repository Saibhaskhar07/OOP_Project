#ifndef BANKEASYAPP_H // Header guard to prevent multiple inclusions
#define BANKEASYAPP_H

#include <iostream>       // Include the standard input/output stream header
#include <fstream>        // Include the file stream header
#include "Accounts.h"     // Include Accounts header for managing user accounts
#include "Admin.h"        // Include Admin header for admin functionalities
#include "Personal.h"     // Include Personal header for personal account functionalities
#include "Commercial.h"   // Include Commercial header for commercial account functionalities
using namespace std;      // Using standard namespace for convenience
using namespace bankeasy; // Using bankeasy namespace for classes

class BankEasyApp
{ // Declare the BankEasyApp class
public:
    void addUserInput(Accounts *accounts)
    {                                              // Method to add a user based on user input
        std::string name, email, pin, accountType; // Declare variables for user details
        Loan *loan = nullptr;                      // Initialize loan pointer
        std::cout << "Enter name: ";               // Prompt for name
        std::cin >> name;                          // Read name
        std::cout << "Enter email: ";              // Prompt for email
        std::cin >> email;                         // Read email
        std::cout << "Enter PIN: ";                // Prompt for PIN
        std::cin >> pin;                           // Read PIN

        if (accounts->type() == "Commercial")
        {                                                            // Check account type
            accountType = "Commercial";                              // Set account type
            accounts->addUser(User(name, email, pin, accountType));  // Add user to accounts
            dynamic_cast<Commercial *>(accounts)->bookAppointment(); // Cast to Commercial and book appointment
        }
        else
        {                                                                 // For Personal accounts
            accountType = Personal::chooseAccountType(loan);              // Choose account type based on loan
            accounts->addUser(User(name, email, pin, accountType, loan)); // Add user to accounts
        }
    }

    void performUserActions(User *user, Accounts *accounts)
    {                  // Method to perform user actions
        int action;    // Declare variable for user action
        double amount; // Declare variable for amount
        do
        {
            std::cout << "Your balance: $" << user->getBalance() << "\n";                                                                                           // Display user's balance
            std::cout << "1. Deposit\n2. Withdraw\n3. Schedule Payment\n4. Update Login Details\n5. Close Account\n6. Manage Cards\n7. Logout\nChoose an option: "; // Menu options
            if (!(cin >> action))
            {                                                                 // Input validation
                cout << "Invalid input. Please enter a valid input." << endl; // Invalid input message
                cin.clear();                                                  // Clear input stream
                cin.ignore(numeric_limits<streamsize>::max(), '\n');          // Ignore invalid input
                continue;                                                     // Continue loop
            }

            switch (action)
            {                                             // Switch based on user action
            case 1:                                       // Deposit
                std::cout << "Enter amount to deposit: "; // Prompt for deposit amount
                if (!(cin >> amount))
                {                                                                 // Input validation
                    cout << "Invalid input. Please enter a valid input." << endl; // Invalid input message
                    cin.clear();                                                  // Clear input stream
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');          // Ignore invalid input
                    continue;                                                     // Continue loop
                }
                user->deposit(amount); // Deposit amount
                accounts->saveUsers(); // Save user data
                break;
            case 2:                                        // Withdraw
                std::cout << "Enter amount to withdraw: "; // Prompt for withdrawal amount
                if (!(cin >> amount))
                {                                                                 // Input validation
                    cout << "Invalid input. Please enter a valid input." << endl; // Invalid input message
                    cin.clear();                                                  // Clear input stream
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');          // Ignore invalid input
                    continue;                                                     // Continue loop
                }
                user->withdraw(amount); // Withdraw amount
                accounts->saveUsers();  // Save user data
                break;
            case 3:
            {                                           // Schedule Payment
                std::string purpose, frequency;         // Declare variables for payment details
                double amount;                          // Declare variable for payment amount
                std::cout << "Enter payment purpose: "; // Prompt for payment purpose
                std::cin.ignore();                      // Ignore newline character
                std::getline(std::cin, purpose);        // Read payment purpose
                std::cout << "Enter payment amount: ";  // Prompt for payment amount
                if (!(cin >> amount))
                {                                                                 // Input validation
                    cout << "Invalid input. Please enter a valid input." << endl; // Invalid input message
                    cin.clear();                                                  // Clear input stream
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');          // Ignore invalid input
                    continue;                                                     // Continue loop
                }
                std::cin.ignore();                                           // Ignore newline character
                std::cout << "Enter payment frequency (biweekly/monthly): "; // Prompt for payment frequency
                std::getline(std::cin, frequency);                           // Read payment frequency
                user->schedulePayment(purpose, amount, frequency);           // Schedule payment
                accounts->saveUsers();                                       // Save user data
                break;
            }
            case 4:
            {                                               // Update Login Details
                std::string newEmail, newPin;               // Declare variables for new login details
                std::cout << "Enter new email: ";           // Prompt for new email
                std::cin >> newEmail;                       // Read new email
                std::cout << "Enter new PIN: ";             // Prompt for new PIN
                std::cin >> newPin;                        // Read new PIN
                user->updateLoginDetails(newEmail, newPin); // Update login details
                accounts->saveUsers();                      // Save user data
                break;                                      // Exit switch
            }
            case 5:                                                   // Close Account
                accounts->deleteUser(user->getEmail());               // Delete user account
                action = 7;                                           // Set action to logout
                break;                                                // Exit switch
            case 6:                                                   // Manage Cards
                user->manageCards();                                  // Manage user cards
                accounts->saveUsers();                                // Save user data
                break;                                                // Exit switch
            case 7:                                                   // Logout
                std::cout << "Logging out...\n\n";                    // Print logout message
                break;                                                // Exit switch
            default:                                                  // Default case for invalid options
                std::cout << "Invalid option. Please try again.\n\n"; // Print invalid option message
            }
        } while (action != 7); // Repeat until logout
    }

    void adminActions(Admin &admin, Accounts *accounts)
    { // Method for admin actions
        if (accounts == nullptr)
        {                                              // Check if accounts exist
            std::cout << "No accounts available.\n\n"; // Print no accounts message
            return;                                    // Return from function
        }
        std::vector<User> &users = accounts->getUsers(); // Get users from accounts
        int choice;                                      // Declare variable for admin choice
        std::string email;                               // Declare variable for user email
        do
        {
            std::cout << "1. View all users\n2. Delete a user\n3. Change interest rate\n4. Freeze transactions\n5. Unfreeze transactions\n6. Update Login Details\n7. Logout\nChoose an option: "; // Admin menu options
            if (!(cin >> choice))
            {                                                                 // Input validation
                cout << "Invalid input. Please enter a valid input." << endl; // Invalid input message
                cin.clear();                                                  // Clear input stream
                cin.ignore(numeric_limits<streamsize>::max(), '\n');          // Ignore invalid input
                continue;                                                     // Continue loop
            }
            switch (choice)
            {                                                                 // Switch based on admin choice
            case 1:                                                           // View all users
                admin.viewAllUsers(users);                                    // View all users
                break;                                                        // Exit switch
            case 2:                                                           // Delete a user
                std::cout << "Enter email of user to delete: ";               // Prompt for user email
                std::cin >> email;                                            // Read user email
                admin.deleteUser(users, email);                               // Delete user
                accounts->saveUsers();                                        // Save user data
                break;                                                        // Exit switch
            case 3:                                                           // Change interest rate
                double newRate;                                               // Declare variable for new interest rate
                std::cout << "Enter email of user to change interest rate: "; // Prompt for user email
                std::cin >> email;                                            // Read user email
                std::cout << "Enter new interest rate: ";                     // Prompt for new interest rate
                if (!(cin >> newRate))
                {                                                                 // Input validation
                    cout << "Invalid input. Please enter a valid input." << endl; // Invalid input message
                    cin.clear();                                                  // Clear input stream
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');          // Ignore invalid input
                    continue;                                                     // Continue loop
                }
                admin.changeInterestRate(users, email, newRate);               // Change interest rate
                accounts->saveUsers();                                         // Save user data
                break;                                                         // Exit switch
            case 4:                                                            // Freeze transactions
                std::cout << "Enter email of user to freeze transactions: ";   // Prompt for user email
                std::cin >> email;                                             // Read user email
                admin.freezeTransactions(users, email);                        // Freeze transactions
                accounts->saveUsers();                                         // Save user data
                break;                                                         // Exit switch
            case 5:                                                            // Unfreeze transactions
                std::cout << "Enter email of user to unfreeze transactions: "; // Prompt for user email
                std::cin >> email;                                             // Read user email
                admin.unfreezeTransactions(users, email);                      // Unfreeze transactions
                accounts->saveUsers();                                         // Save user data
                break;                                                         // Exit switch
            case 6:                                                            // Update Login Details
                std::cout << "Enter email of user to update login details: ";  // Prompt for user email
                std::cin >> email;                                             // Read user email
                admin.updateLoginDetails(users, email);                        // Update login details
                accounts->saveUsers();                                         // Save user data
                break;                                                         // Exit switch
            case 7:                                                            // Logout
                std::cout << "Logging out...\n\n";                             // Print logout message
                break;                                                         // Exit switch
            default:                                                           // Default case for invalid options
                std::cout << "Invalid option. Please try again.\n\n";          // Print invalid option message
            }
        } while (choice != 7); // Repeat until logout
    }

    Accounts *loadAccounts()
    {                                         // Method to load accounts from file
        std::ifstream inFile("accounts.dat"); // Open file for reading
        if (inFile.is_open() && inFile.peek() != EOF)
        {                                      // Check if file is open and not empty
            std::string accountType;           // Declare variable for account type
            std::getline(inFile, accountType); // Read account type from file
            inFile.close();                    // Close file
            if (accountType == "Commercial")
            {                            // Check account type
                return new Commercial(); // Return Commercial account
            }
            else if (accountType == "Personal")
            {                          // Check account type
                return new Personal(); // Return Personal account
            }
        }
        return nullptr; //

        return nullptr; // Return nullptr if no valid account type found
    }

    void run()
    {                                            // Method to run the BankEasy application
        std::cout << "Welcome to BankEasy!\n\n"; // Print welcome message

        Accounts *accounts = loadAccounts(); // Load accounts from file

        Admin admin("Admin", "admin@bankeasy.com", "adminpass"); // Create admin object
        int choice;                                              // Declare variable for user choice

        do
        {
            std::cout << "1. Sign Up\n2. Log In\n3. Admin Login\n4. Exit\nChoose an option: "; // Menu options
            if (!(cin >> choice))
            {                                                                 // Input validation
                cout << "Invalid input. Please enter a valid input." << endl; // Invalid input message
                cin.clear();                                                  // Clear input stream
                cin.ignore(numeric_limits<streamsize>::max(), '\n');          // Ignore invalid input
                continue;                                                     // Continue loop
            }

            switch (choice)
            { // Switch based on user choice
            case 1:
            {                                              // Sign Up
                std::cout << "Choose account category:\n"; // Prompt for account category
                std::cout << "1. Commercial\n";            // Commercial option
                std::cout << "2. Personal\n";              // Personal option
                std::cout << "Enter your choice: ";        // Prompt for choice
                if (!(cin >> choice))
                {                                                                 // Input validation
                    cout << "Invalid input. Please enter a valid input." << endl; // Invalid input message
                    cin.clear();                                                  // Clear input stream
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');          // Ignore invalid input
                    continue;                                                     // Continue loop
                }
                std::cin.ignore(); // Ignore newline character

                if (choice == 1)
                {                                // Commercial account
                    accounts = new Commercial(); // Create Commercial account
                }
                else if (choice == 2)
                {                              // Personal account
                    accounts = new Personal(); // Create Personal account
                }
                else
                {                                                                 // Invalid choice
                    std::cout << "Invalid choice. Exiting account creation.\n\n"; // Print invalid choice message
                    break;                                                        // Exit switch
                }
                addUserInput(accounts); // Add user based on input
                break;                  // Exit switch
            }
            case 2:
            { // Log In
                if (accounts == nullptr)
                {                                                                      // Check if accounts exist
                    std::cout << "No accounts created yet. Please sign up first.\n\n"; // Print no accounts message
                    break;                                                             // Exit switch
                }
                std::string email, pin;                // Declare variables for email and PIN
                std::cout << "Enter email to login: "; // Prompt for email
                std::cin >> email;                     // Read email
                std::cout << "Enter PIN: ";            // Prompt for PIN
                std::cin >> pin;                       // Read PIN

                User *user = accounts->login(email, pin); // Attempt login
                if (user != nullptr)
                {                                                                    // Successful login
                    std::cout << "Welcome, " << user->getName() << "!\n";            // Print welcome message
                    std::cout << "Email: " << user->getEmail() << "\n";              // Print email
                    std::cout << "Account Type: " << user->getAccountType() << "\n"; // Print account type
                    std::cout << "Balance: $" << user->getBalance() << "\n\n";       // Print balance
                    performUserActions(user, accounts);                              // Perform user actions
                }
                else
                {                                                           // Failed login
                    std::cout << "Login failed. Invalid email or PIN.\n\n"; // Print login failed message
                }
                break; // Exit switch
            }
            case 3:
            {                                 // Admin Login
                std::string email, password;  // Declare variables for email and password
                std::cout << "Admin Login\n"; // Print admin login message
                std::cout << "Email: ";       // Prompt for email
                std::cin >> email;            // Read email
                std::cout << "Password: ";    // Prompt for password
                std::cin >> password;         // Read password

                if (admin.getAdminEmail() == email && admin.authenticate(password))
                {                                                                // Check admin credentials
                    std::cout << "Welcome, " << admin.getAdminName() << "!\n\n"; // Print welcome message
                    adminActions(admin, accounts);                               // Perform admin actions
                }
                else
                {                                                  // Invalid credentials
                    std::cout << "Invalid email or password.\n\n"; // Print invalid credentials message
                }
                break; // Exit switch
            }
            case 4:                                                   // Exit
                std::cout << "Exiting...\n\n";                        // Print exit message
                break;                                                // Exit switch
            default:                                                  // Default case for invalid options
                std::cout << "Invalid option. Please try again.\n\n"; // Print invalid option message
            }
        } while (choice != 4); // Repeat until exit

        std::cout << "Thank you for banking with BankEasy!\n"; // Print farewell message
        delete accounts;                                       // Delete accounts object
    }
};

#endif // BANKEASYAPP_H // End of header guard and file
