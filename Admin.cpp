#include "Admin.h"
#include <iostream>
#include <algorithm> // Include this for std::remove_if

Admin::Admin(const std::string& adminName, const std::string& adminEmail, const std::string& adminPassword)
    : adminName(adminName), adminEmail(adminEmail), adminPassword(adminPassword) {}

std::string Admin::getAdminName() const {
    return adminName;
}

std::string Admin::getAdminEmail() const {
    return adminEmail;
}

bool Admin::authenticate(const std::string& adminPassword) const {
    return this->adminPassword == adminPassword;
}

void Admin::viewAllUsers(const std::vector<User>& users) const {
    for (const User& user : users) {
        std::cout << "Name: " << user.getName() << ", Email: " << user.getEmail() << ", Balance: $" << user.getBalance() << std::endl;
    }
}

void Admin::deleteUser(std::vector<User>& users, const std::string& email) {
    auto it = std::remove_if(users.begin(), users.end(),
        [&email](const User& user) {
            return user.getEmail() == email;
        });
    if (it != users.end()) {
        users.erase(it, users.end());
    }
}
