#include "Accounts.h"
#include "User.h"
#include <fstream>
#include <iostream>
#include <algorithm>

namespace bankeasy {

Accounts::Accounts() {}

Accounts::~Accounts() {}

void Accounts::saveUsers() const {
    std::ofstream outFile("accounts.dat", std::ios::trunc); // Open file in truncation mode to overwrite existing content
    if (outFile.is_open()) {
        for (const auto& user : users) {
            user.save(outFile);
        }
    }
}

std::vector<User>& Accounts::getUsers() {
    return users;
}

void Accounts::addUser(const User& user) {
    users.push_back(user);
    saveUsers(); // Save the user immediately after adding
}

User* Accounts::login(const std::string& email, const std::string& pin) {
    for (auto& user : users) {
        if (user.getEmail() == email && user.getPin() == pin) {
            return &user;
        }
    }
    return nullptr;
}

void Accounts::deleteUser(const std::string& email) {
    auto it = std::remove_if(users.begin(), users.end(), [&email](const User& user) {
        return user.getEmail() == email;
    });
    users.erase(it, users.end());
    saveUsers(); // Save the users immediately after deletion
}

} // namespace bankeasy
