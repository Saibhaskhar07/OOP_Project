#include "Accounts.h"
#include <fstream>

namespace bankeasy {

User* Accounts::login(const std::string& email, const std::string& pin) {
    for (auto& user : users) {
        if (user.getEmail() == email && user.getPin() == pin) {
            return &user;
        }
    }
    return nullptr;
}

void Accounts::addUser(const User& user) {
    users.push_back(user);
    saveUsers();
}

void Accounts::deleteUser(const std::string& email) {
    users.erase(std::remove_if(users.begin(), users.end(), [&email](const User& user) {
        return user.getEmail() == email;
    }), users.end());
    saveUsers();
}

void Accounts::saveUsers() const {
    std::ofstream outFile("accounts.dat");
    for (const auto& user : users) {
        user.save(outFile);
    }
}

std::vector<User>& Accounts::getUsers() {
    return users;
}

} // namespace bankeasy
