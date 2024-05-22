#include "Admin.h"
#include "Utils.h"
#include <iostream>

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
        std::cout << "No users found.\n\n";
        return;
    }
    for (const auto& user : users) {
        std::cout << "Name: " << user.getName() << ", Email: " << user.getEmail() << ", Balance: $" << user.getBalance() << ", Account Type: " << user.getAccountType() << "\n";
    }
    std::cout << "\n";
}

void Admin::deleteUser(std::vector<User>& users, const std::string& email) {
    users.erase(std::remove_if(users.begin(), users.end(), [&email](const User& user) {
        return user.getEmail() == email;
    }), users.end());
    std::cout << "User deleted successfully.\n\n";
}

void Admin::changeInterestRate(std::vector<User>& users, const std::string& email, double newRate) {
    for (auto& user : users) {
        if (user.getEmail() == email) {
            user.changeInterestRate(newRate);
            std::cout << "Interest rate changed successfully.\n\n";
            return;
        }
    }
    std::cout << "User not found.\n\n";
}

void Admin::freezeTransactions(std::vector<User>& users, const std::string& email) {
    for (auto& user : users) {
        if (user.getEmail() == email) {
            user.freezeTransactions();
            std::cout << "Transactions frozen successfully.\n\n";
            return;
        }
    }
    std::cout << "User not found.\n\n";
}

void Admin::unfreezeTransactions(std::vector<User>& users, const std::string& email) {
    for (auto& user : users) {
        if (user.getEmail() == email) {
            user.unfreezeTransactions();
            std::cout << "Transactions unfrozen successfully.\n\n";
            return;
        }
    }
    std::cout << "User not found.\n\n";
}

void Admin::updateLoginDetails(std::vector<User>& users, const std::string& email) {
    for (auto& user : users) {
        if (user.getEmail() == email) {
            std::string newEmail, newPin;
            std::cout << "Enter new email: ";
            newEmail = getValidatedEmailInput();
            std::cout << "Enter new PIN: ";
            newPin = getValidatedPinInput();
            user.updateLoginDetails(newEmail, newPin);
            std::cout << "Login details updated successfully.\n\n";
            return;
        }
    }
    std::cout << "User not found.\n\n";
}

void Admin::changePin(std::vector<User>& users, const std::string& email) {
    for (auto& user : users) {
        if (user.getEmail() == email) {
            std::string newPin;
            std::cout << "Enter new PIN: ";
            newPin = getValidatedPinInput();
            user.updateLoginDetails(user.getEmail(), newPin);
            std::cout << "PIN changed successfully.\n\n";
            return;
        }
    }
    std::cout << "User not found.\n\n";
}

} // namespace bankeasy