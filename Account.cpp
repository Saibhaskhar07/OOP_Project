#include "Account.h"

Account::Account(const string& name, const string& email, int age)
    : name(name), email(email), age(age), accNo(0), balance(0) {}

void Account::set_name(const string& Name) {
    name = Name;
}

void Account::set_email(const string& Email) {
    email = Email;
}

void Account::set_age(int Age) {
    age = Age;
}

string Account::get_name() const {
    return name;
}

string Account::get_email() const {
    return email;
}

int Account::get_age() const {
    return age;
}
