#include<iostream>
using namespace std;


class Card {
        private:
                int value;

        public:
                int suit;
                int number;
                Card(int val) {
                        value = val;
                        suit = (value / 13) % 4;
                        number = value % 13;
                }

                friend ostream& operator<<(ostream& os, const Card& card);

                friend bool operator==(const Card& left, const Card& right);
                friend bool operator!=(const Card& left, const Card& right);
                
                friend bool operator<(const Card& left, const Card& right);
                friend bool operator>(const Card& left, const Card& right);
                friend bool operator>=(const Card& left, const Card& right);
                friend bool operator<=(const Card& left, const Card& right);
};
