#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <vector>
#include "User.h"

namespace bankeasy {

class Accounts {
public:
    virtual ~Accounts() = default;
    virtual std::string type() const = 0;
    virtual User* login(const std::string& email, const std::string& pin);
    virtual void addUser(const User& user);
    virtual void deleteUser(const std::string& email);
    virtual void saveUsers() const;
    virtual std::vector<User>& getUsers();
protected:
    std::vector<User> users;
};

} // namespace bankeasy

#endif // ACCOUNTS_H
