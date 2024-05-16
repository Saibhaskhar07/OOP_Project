#include "Accounts.h"
#include <fstream>

Accounts::Accounts() {
    loadUsers();
}

Accounts::~Accounts() {
    saveUsers();
}

void Accounts::addUser(const User& user) {
    users.push_back(user);
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
    }
}

void Accounts::saveUsers() {
    std::ofstream outFile("accounts.dat");
    for (const User& user : users) {
        user.save(outFile);
    }
    outFile.close();
}
