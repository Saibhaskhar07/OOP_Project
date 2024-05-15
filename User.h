#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>
#include "Accounts.h"

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
    void displayUserAccounts(const User& user);
private:
    std::vector<User> users;
    User* currentUser;
    bool checkCredentials(const std::string& email, const std::string& password);
    void loadUsers();
    void saveUsers();
};

#endif // USER_H
