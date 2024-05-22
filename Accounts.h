#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <vector>
#include "User.h"

namespace bankeasy {

class Accounts {
public:
    Accounts();
    virtual ~Accounts();

    virtual std::string type() const = 0;
    void addUser(const User& user);
    User* login(const std::string& email, const std::string& pin);
    void deleteUser(const std::string& email);
    void saveUsers() const;
    std::vector<User>& getUsers();

private:
    std::vector<User> users;
    void loadUsers() ; 
};

} // namespace bankeasy

#endif // ACCOUNTS_H