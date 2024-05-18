#include "Admin.h"
#include <iostream>
#include <algorithm>

namespace bankeasy {

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
    if (users.empty()) {
        std::cout << "No users available.\n\n";
        return;
    }
    for (const User& user : users) {
        std::cout << "Name: " << user.getName() << ", Email: " << user.getEmail() << ", Balance: $" << user.getBalance() << ", Account Type: " << user.getAccountType() << "\n";
    }
    std::cout << "\n";
}

void Admin::deleteUser(std::vector<User>& users, const std::string& email) {
    auto it = std::remove_if(users.begin(), users.end(),
        [&email](const User& user) {
            return user.getEmail() == email;
        });
    if (it != users.end()) {
        std::cout << "Deleting user with email: " << email << "\n";
        users.erase(it, users.end());
        std::cout << "User deleted successfully.\n\n";
    } else {
        std::cout << "User not found.\n\n";
    }
}

void Admin::changeInterestRate(std::vector<User>& users, const std::string& email, double newRate) {
    for (User& user : users) {
        if (user.getEmail() == email && user.getAccountType().find("Loan") != std::string::npos) {
            user.changeInterestRate(newRate);
            std::cout << "Interest rate changed successfully.\n\n";
            return;
        }
    }
    std::cout << "User not found or not a loan account.\n\n";
}

void Admin::freezeTransactions(std::vector<User>& users, const std::string& email) {
    for (User& user : users) {
        if (user.getEmail() == email) {
            user.freezeTransactions();
            std::cout << "Transactions frozen successfully.\n\n";
            return;
        }
    }
    std::cout << "User not found.\n\n";
}

void Admin::unfreezeTransactions(std::vector<User>& users, const std::string& email) {
    for (User& user : users) {
        if (user.getEmail() == email) {
            user.unfreezeTransactions();
            std::cout << "Transactions unfrozen successfully.\n\n";
            return;
        }
    }
    std::cout << "User not found.\n\n";
}

} // namespace bankeasy
