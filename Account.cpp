#include "Account.h"

Account::Account(const std::string& name, const std::string& email, int age)
    : name(name), email(email), age(age), accNo(0), balance(0) {}

void Account::set_name(const std::string& Name) {
    name = Name;
}

void Account::set_email(const std::string& Email) {
    email = Email;
}

void Account::set_age(int Age) {
    age = Age;
}

std::string Account::get_name() const {
    return name;
}

std::string Account::get_email() const {
    return email;
}

int Account::get_age() const {
    return age;
}
