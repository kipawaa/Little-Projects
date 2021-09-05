#pragma once

#include"card.hpp"

#include<iostream>
#include<random>

class Deck {
        private:
                std::vector<Card> cards;
                std::vector<Card> discards;
        
        public:
                Deck() {
                        for (int suit = 0; suit < 4; suit++) {
                                for (int val = 0; val < 13; val++) {
                                        cards.push_back(Card(suit, val));
                                }
                        }
                }

                // operators
                friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
                
                // general functions
                int getLength(void);
                Card takeCard(void);
                void flipCard(void);

                // shuffling
                void wash(void);
                void riffleShuffle(void);
                void nRiffleShuffle(int n);
                void strip();
                Card cut(void);

                // testing
                void verify(void);

};
