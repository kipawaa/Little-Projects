#include"card.h"

Card* newCard(int suit, int value) {
        Card* card = (Card*)calloc(1, sizeof(card));

        card -> suit = suit;
        card -> value = value;
        card -> next = NULL;
        
        return card;
}

int deleteCard(Card* card) {
        // return -1 as error if next is not null.
        // this is to avoid memory leaks
        if (card -> next != NULL) return -1;
        free(card);
        return 0;
}
