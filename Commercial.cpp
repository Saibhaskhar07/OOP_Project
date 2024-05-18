#include "Commercial.h"

Commercial::Commercial() : Accounts() {}

std::string Commercial::type() const {
    return "Commercial";
}
