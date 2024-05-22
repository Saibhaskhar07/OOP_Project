#ifndef CARDS_H // Header guard to prevent multiple inclusion
#define CARDS_H

#include <string> // Include necessary header files

namespace bankeasy { // Begin namespace bankeasy

class Cards { // Declare Cards class
public: // Public access specifier
    Cards(const std::string& type, long long int number, const std::string& start, const std::string& expiry, int cvv, double limit); // Constructor
    std::string getType() const; // Getter method for card type
    long long int getNumber() const; // Getter method for card number
    std::string getStart() const; // Getter method for card start date
    std::string getExpiry() const; // Getter method for card expiry date
    int getCVV() const; // Getter method for card CVV
    double getLimit() const; // Getter method for card limit
    bool getStatus() const; // Getter method for card status
    void activateCard(); // Method to activate card
    void deactivateCard(); // Method to deactivate card
    void updateLimit(double newLimit); // Method to update card limit
    void displayCardDetails() const; // Method to display card details

private: // Private access specifier
    std::string type; // Member variable for card type
    long long int number; // Member variable for card number
    std::string start; // Member variable for card start date
    std::string expiry; // Member variable for card expiry date
    int cvv; // Member variable for card CVV
    double limit; // Member variable for card limit
    bool active; // Member variable for card status
};

} // End namespace bankeasy

#endif // End of header guard and file
