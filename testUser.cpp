#include "User.h"
#include <cassert>
#include <iostream>
#include <sstream>

void testSignUp(UserManager& userManager) {
    // Redirect standard input to simulate user input for sign-up
    std::istringstream signUpInput("Alice\nJohnson\nalice@example.com\nalicepass\n");
    std::streambuf* origCin = std::cin.rdbuf(signUpInput.rdbuf());

    userManager.signUp();

    // Restore standard input
    std::cin.rdbuf(origCin);

    // Check if the user is added correctly
    assert(userManager.checkCredentials("alice@example.com", "alicepass") == true);
    User* user = userManager.getUserByEmail("alice@example.com");
    assert(user != nullptr);
    assert(user->accounts.size() == 2); // Default accounts
    std::cout << "Test Sign Up passed!\n";
}

void testLogin(UserManager& userManager) {
    // Redirect standard input to simulate user input for login
    std::istringstream loginInput("alice@example.com\nalicepass\n");
    std::streambuf* origCin = std::cin.rdbuf(loginInput.rdbuf());

    bool loginSuccess = userManager.login();

    // Restore standard input
    std::cin.rdbuf(origCin);

    // Test successful login
    assert(loginSuccess == true);

    // Redirect standard input to simulate user input for unsuccessful login
    std::istringstream loginInputFail("alice@example.com\nwrongpass\n");
    origCin = std::cin.rdbuf(loginInputFail.rdbuf());

    loginSuccess = userManager.login();

    // Restore standard input
    std::cin.rdbuf(origCin);

    // Test unsuccessful login
    assert(loginSuccess == false);

    std::cout << "Test Login passed!\n";
}

void testViewAccounts(UserManager& userManager) {
    User* user = userManager.getUserByEmail("alice@example.com");
    assert(user != nullptr);
    std::cout << "Testing view accounts...\n";
    userManager.viewAccounts(*user);
    std::cout << "View accounts test passed!\n";
}

int main() {
    UserManager userManager;

    // Load users to ensure persistence across tests
    userManager.loadUsers();

    // Run tests
    testSignUp(userManager);
    testLogin(userManager);
    testViewAccounts(userManager);

    std::cout << "All tests passed!\n";

    return 0;
}
