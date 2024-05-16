#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <vector>
#include "User.h"

class Accounts {
public:
    Accounts();
    virtual ~Accounts();
    void addUser(const User& user);
    User* login(const std::string& email, const std::string& pin);
    std::vector<User>& getUsers();
    virtual std::string type() const = 0; // Pure virtual function

private:
    std::vector<User> users;
    void loadUsers();
    void saveUsers();
};

#endif // ACCOUNTS_H
