#include"deck.h"


Deck* newDeck(void) {
        Deck* deck = (Deck*)malloc(sizeof(Deck));
        
        // initialize values
        deck -> length = 52;
        deck -> index = 0;

        // fill the deck
        for (char suit = 0; suit < 4; suit++) {
                for (char val = 0; val < 13; val++) {
                        deck -> cards[suit * 13 + val] = suit * 13 + val;
                }
        }
        
        return deck;
}


int getNext(Deck* deck) {
        // the ternary expression on the right determines the index of the first element in the queue.
        // if that is beyond index 0, then it returns the value before it, otherwise it returns the end of the array
        if (deck -> length == ((deck -> index > 0) ? deck -> index - 1 : 53)) {
                printf("I'm empty!!!\n");
                return -1;
        }
        int temp = deck -> cards[deck -> index];
        deck -> index = (deck -> index) < (53 - 1) ? (deck -> index + 1) : 0; 
        return temp;
}


/*
void overhandShuffle(Deck* deck) {
        srand(time());
        
        int total = 0;

        while (total < deck -> length) {
                int numCards = rand() % (deck -> length / 3);
                
}
*/


void cardToString(char* string, int numBytes, int card) {
        int suitVal = card / 13;
        int numVal = card % 13 + 1;

        char* suit;
        char val[3];

        if (suitVal == 0) suit = "\u2660";
        else if (suitVal == 1) suit = "\u2665";
        else if (suitVal == 2) suit = "\u2666";
        else if (suitVal == 3) suit = "\u2663";

        if (numVal == 13) strncpy(val, "K", 3);
        else if (numVal == 12) strncpy(val, "Q", 3);
        else if (numVal == 11) strncpy(val, "J", 3);
        else if (numVal == 1) strncpy(val, "A", 3);
        else snprintf(val, 3,  "%d", numVal);
        
        snprintf(string, numBytes, "%s%s", val, suit);
}


void printDeck(Deck* deck) {
        int i = 0;
        while ((deck -> index + i) % 53 != deck -> length) {
                char card[10];
                cardToString(card, 10, deck -> cards[(deck -> index + i) % 53]);
                printf("%s, ", card);
                i++;
        }
        printf("\n");
}
