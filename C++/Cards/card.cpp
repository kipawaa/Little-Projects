#include"card.hpp"

std::ostream& operator<<(std::ostream& os, const Card& card) {
        os << NUMBERS[card.second] << SUITS[card.first];
        return os;
}
