#ifndef CARDS_H
#define CARDS_H

#include <string>

namespace bankeasy { // start ofg the namespace bankeasy

class Cards { // Define Card class
public:
    Cards(const std::string& type, long long int number, const std::string& start, const std::string& expiry, int cvv, double limit); // constructor
    // Get card parameters
    std::string getType() const;
    long long int getNumber() const;
    std::string getStart() const;
    std::string getExpiry() const;
    int getCVV() const;
    double getLimit() const;
    bool getStatus() const;
    void activateCard();
    void deactivateCard();
    void updateLimit(double newLimit);
    // Display the card parameters
    void displayCardDetails() const;

private:
    std::string type;
    long long int number;
    std::string start;
    std::string expiry;
    int cvv;
    double limit;
    bool active;
};

} // end of namespace bankeasy

#endif // CARDS_H