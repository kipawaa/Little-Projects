#include"Card.h"

#include<iostream.h>
using namespace std

class Hand {
        private:

        public:
                int numCards;
                Card* cards;
                
                Hand Hand(int numCards) {
                        cards = (Card*)calloc(numCards * sizeof(Card));
                }

                void sortHand(void);
        }
}
