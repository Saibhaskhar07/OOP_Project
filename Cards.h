#ifndef CARDS_H
#define CARDS_H

#include <string>

namespace bankeasy {

class Cards {
public:
    Cards(const std::string& type, long long int number, const std::string& start, const std::string& expiry, int cvv, double limit);
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

} // namespace bankeasy

#endif // CARDS_H