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
            user.processScheduledPayments();
            saveUsers();
            return &user;
        }
    }
    return nullptr;
}

std::vector<User>& Accounts::getUsers() {
    return users;
}

void Accounts::deleteUser(const std::string& email) {
    auto it = std::remove_if(users.begin(), users.end(),
        [&email](const User& user) {
            return user.getEmail() == email;
        });
    if (it != users.end()) {
        users.erase(it, users.end());
        saveUsers();
        std::cout << "User deleted successfully.\n\n";
    } else {
        std::cout << "User not found.\n\n";
    }
}

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

void Accounts::saveUsers() {
    std::ofstream outFile("accounts.dat");
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
