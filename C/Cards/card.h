#include<stdlib.h>

// Card structure that stores suit, value and next
typedef struct Card {
        int suit;
        int value;
        struct Card* next;
} Card;

// returns a pointer to a new card with suit and value pre-set
Card* newCard(int suit, int value);

// deletes card and returns 0 on success. returns -1 if next is not null to avoid memory leaks
int deleteCard(Card* card);
