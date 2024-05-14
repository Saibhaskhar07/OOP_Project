#ifndef ACCOUNT_H
#define ACCOUNT_H
// Header guards to prevent multiple inclusions of the same header file
#include <iostream>
#include <string>
using namespace std;

class Account {
    // Attributes required for account creation
protected:
    string name;        // Name of the account holder
    string email;       // Email of the account holder
    int age;            // Age of the account holder
    long int accNo;     // Account number
    string transactions;    // Transaction history

public:
    Account();  // Default constructor declaration

    // Setter methods to assign values to account attributes
    void set_name(string Name);
    void set_email(string Email);
    void set_age(int Age);

    // Getter methods to retrieve values of account attributes
    string get_name();
    string get_email();
    int get_age();
};
#endif // End of header guard