#include "Accounts.h"
#include <fstream>
#include <iostream>

namespace bankeasy {

Accounts::Accounts() {
    loadUsers();
}

Accounts::~Accounts() {
    saveUsers();
}

void Accounts::addUser(const User& user) {
    users.push_back(user);
    saveUsers();
    std::cout << "Account created successfully.\n\n";
}

User* Accounts::login(const std::string& email, const std::string& pin) {
    for (User& user : users) {
        if (user.getEmail() == email && user.getPin() == pin) {
            return &user;
        }
    }
    return nullptr;
}

std::vector<User>& Accounts::getUsers() {
    return users;
}

void Accounts::loadUsers() {
    std::ifstream inFile("accounts.dat");
    if (inFile.is_open()) {
        while (inFile.peek() != EOF) {
            User user = User::load(inFile);
            users.push_back(user);
        }
        inFile.close();
    } else {
        std::cout << "No existing accounts found.\n";
    }
}

void Accounts::saveUsers() {
    std::ofstream outFile("accounts.dat");
    if (outFile.is_open()) {
        for (const User& user : users) {
            user.save(outFile);
        }
        outFile.close();
    } else {
        std::cerr << "Failed to open accounts.dat for writing.\n";
    }
}

} // namespace bankeasy
