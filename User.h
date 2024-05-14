#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>

struct User {
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string password;
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
    bool checkCredentials(const std::string& email, const std::string& password);
    void loadUsers();
    void saveUsers();
};

#endif // USER_H
