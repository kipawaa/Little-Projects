#include"card.h"

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class Deck {
        private:
                int length;
                Card* cards;

                int numDiscards;
                Card* discard;
        public:
                Deck(int len) {
                        length = len;

                        cards = (Card*)malloc(len * sizeof(Card));
                        for (int i = 0; i < len; i++) {
                                cards[i] = Card(i);
                        }

                        numDiscards = 0;
                        discard = (Card*)malloc(len * sizeof(Card));
                }

                // operator overloads
                friend ostream& operator<<(ostream& os, const Deck& deck);
                
                // general functions
                int getLength(void);
                Card takeCard(void);
                Card flipCard(void);

                // shuffling
                void wash(void);
                void riffleShuffle(void);
                void nRiffleShuffle(int n);
                void strip();
                Card cut(void);

                // testing
                void verify(void);

};
