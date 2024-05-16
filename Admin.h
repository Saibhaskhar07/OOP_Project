#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>
#include "User.h"

class Admin {
public:
    Admin(const std::string& adminName, const std::string& adminEmail, const std::string& adminPassword);
    std::string getAdminName() const;
    std::string getAdminEmail() const;
    bool authenticate(const std::string& adminPassword) const;
    void viewAllUsers(const std::vector<User>& users) const;
    void deleteUser(std::vector<User>& users, const std::string& email);

private:
    std::string adminName;
    std::string adminEmail;
    std::string adminPassword;
};

#endif // ADMIN_H
