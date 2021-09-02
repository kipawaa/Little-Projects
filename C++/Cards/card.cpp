#include"card.h"

const char* SUITS[4] = {"\u2660", "\u2665", "\u2666", "\u2663"};

const char* NUMBERS[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

ostream& operator<<(ostream& os, const Card& card) {
        os << NUMBERS[card.number] << SUITS[card.suit];
        return os;
}

bool operator==(const Card& left, const Card& right) {
        return left.suit == right.suit && left.number == right.number;
}

bool operator<(const Card& left, const Card& right) {
        if (left.suit < right.suit) return true;
        if (left.suit == right.suit) return left.number < right.number;
        else return false;
}

bool operator>(const Card& left, const Card& right) {
        return operator<(right, left);
}

bool operator<=(const Card& left, const Card& right) {
        return !operator>(left, right);
}

bool operator>=(const Card& left, const Card& right) {
        return !operator<(left, right);
}
