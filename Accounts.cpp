#include "Accounts.h"
#include "User.h"
#include <fstream>
#include <iostream>
#include <algorithm>

namespace bankeasy {

Accounts::Accounts() {}

Accounts::~Accounts() {}

void Accounts::loadUsers() {
    std::ifstream inFile("accounts.dat");
    if (inFile.is_open()) {
        std::string accountType;
        std::getline(inFile, accountType);
        while (inFile.peek() != EOF) {
            User user = User::load(inFile);
            users.push_back(user);
        }
        inFile.close();
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

void Accounts::saveUsers() const
{
    std::ofstream outFile("accounts.dat",std::ios::app);
    if (outFile.is_open()) {
        if (!users.empty()) {
            outFile << users.front().getAccountType() << '\n';
        }
        for (const User& user : users) {
            user.save(outFile);
        }
        outFile.close();
    } else {
        std::cerr << "Failed to open accounts.dat for writing.\n";
    }
}

} // namespace bankeasy