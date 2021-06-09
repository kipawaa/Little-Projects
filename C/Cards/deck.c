#include"deck.h"

Deck* newDeck(void) {
        Deck* deck = (Deck*)calloc(1, sizeof(Deck));

        for (int suit = 0; suit < 4; suit++) {
                for (int val = 0; val < 13; val++) {
                        card = newCard(suit, val);
                        card -> next = deck -> next;
                        deck -> next = card;
                }
        }

        return Deck;
}
