#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
using namespace std;

class Account {
protected:
    string name;
    string email;
    int age;
    long int accNo;
    int balance;

public:
    Account(const string& name = "", const string& email = "", int age = 0);
    virtual void type(const string& p) = 0;
    virtual void displayAccountDetails() const = 0;

    void set_name(const string& Name);
    void set_email(const string& Email);
    void set_age(int Age);
    string get_name() const;
    string get_email() const;
    int get_age() const;
};

#endif
