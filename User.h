#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
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

private:
    std::vector<User> users;
    User* currentUser;
    void loadUsers();
    void saveUsers();
    void createAccount();
    std::string generateAccountNumber();
};

#endif // USER_H
