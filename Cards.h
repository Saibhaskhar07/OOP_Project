#ifndef CARDS_H
#define CARDS_H

#include <string>

namespace bankeasy {

class Cards {
public:
    Cards(const std::string& cardType, long int cardNumber, const std::string& cardStart, const std::string& cardExpiry, int cvv, double limit);
    void activateCard();
    void deactivateCard();
    void updateLimit(double newLimit);
    void displayCardDetails() const;

    // Accessor methods
    std::string getType() const;
    long int getNumber() const;
    std::string getStart() const;
    std::string getExpiry() const;
    int getCVV() const;
    double getLimit() const;
    bool getStatus() const;

private:
    std::string cardType;
    long int cardNumber;
    std::string cardStart;
    std::string cardExpiry;
    int cvv;
    double limit;
    bool isActive;
};

} // namespace bankeasy

#endif // CARDS_H
