#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

class Account {
protected:
    std::string name;
    std::string email;
    int age;
    long int accNo;
    int balance;

public:
    Account(const std::string& name = "", const std::string& email = "", int age = 0);
    virtual void type(const std::string& p) = 0;
    virtual void displayAccountDetails() const = 0;

    void set_name(const std::string& Name);
    void set_email(const std::string& Email);
    void set_age(int Age);
    std::string get_name() const;
    std::string get_email() const;
    int get_age() const;
};

#endif
