#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <fstream> // Include for file handling

class User {
public:
    User(const std::string& name, const std::string& email, const std::string& pin, const std::string& accountType, const std::string& extraInfo);
    std::string getName() const;
    std::string getEmail() const;
    std::string getPin() const;
    std::string getAccountType() const;
    std::string getExtraInfo() const;
    double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void save(std::ofstream& out) const;
    static User load(std::ifstream& in);

private:
    std::string name;
    std::string email;
    std::string pin;
    std::string accountType;
    std::string extraInfo;
    double balance;
};

#endif // USER_H
