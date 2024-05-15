#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>

struct Account {
    std::string accountType;
    double balance;
};

struct User {
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string password;
    std::vector<Account> accounts;
};

class UserManager {
public:
    UserManager();
    ~UserManager();
    void signUp();
    bool login();
    void showMenu();
    void showUserMenu(User& user);
    User* getUserByEmail(const std::string& email);
    void loadUsers();
    void saveUsers();
    void viewAccounts(const User& user);
    bool checkCredentials(const std::string& email, const std::string& password);

private:
    std::vector<User> users;
    void performTransaction(User& user);
};

#endif // USER_H
