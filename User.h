#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
public:
    User(const std::string& name, const std::string& email, const std::string& pin);
    std::string getName() const;
    std::string getEmail() const;
    std::string getPin() const;
    double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void save(std::ofstream& out) const;
    static User load(std::ifstream& in);

private:
    std::string name;
    std::string email;
    std::string pin;
    double balance;
};

#endif // USER_H
