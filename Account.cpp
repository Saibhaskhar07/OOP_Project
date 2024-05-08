#include <iostream> // Standard input/output stream library
#include "Account.h" // Include the declaration of the Account class

using namespace std; // Using the standard namespace

// Implementation of the default constructor for the Account class
Account::Account()
{
    // Initialize attributes to default values
    this->name = " ";
    this->email = " ";
    this->age = 0;
    this->accNo = 0;
    this->transactions = " ";
}

// Setter method for the name attribute
void Account::set_name(string Name)
{
    this->name = Name; // Set the name attribute to the provided value
}

// Setter method for the email attribute
void Account::set_email(string Email)
{
    this->email = Email; // Set the email attribute to the provided value
}

// Setter method for the age attribute
void Account::set_age(int Age)
{
    this->age = Age; // Set the age attribute to the provided value
}

// Getter method for the name attribute
string Account::get_name()
{
    return this->name; // Return the value of the name attribute
}

// Getter method for the email attribute
string Account::get_email()
{
    return this->email; // Return the value of the email attribute
}

// Getter method for the age attribute
int Account::get_age()
{
    return this->age; // Return the value of the age attribute
}
