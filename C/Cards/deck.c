#include"deck.h"


Deck* newDeck(void) {
        // get space for deck
        Deck* deck = (Deck*)malloc(sizeof(Deck));
        
        // set length
        deck -> length = 52;

        // fill the deck
        for (char suit = 0; suit < 4; suit++) {
                for (char val = 0; val < 13; val++) {
                        deck -> cards[suit * 13 + val] = suit * 13 + val;
                }
        }
        
        return deck;
}


void addToEnd(Deck* deck, int card) {
        // check for space
        if (deck -> length == 52) {
                perror("Deck is full!");
                exit(0);
        }

        // assign card
        deck -> cards[deck -> length] = card;
        
        // update length
        deck -> length += 1;
}


int getNext(Deck* deck) {
        // make sure there are cards
        if (deck -> length == 0) {
                perror("Deck is empty!");
                exit(0);
        }
        
        // update length
        deck -> length -= 1;

        // return the desired card
        return deck -> cards[deck -> length];
}


void overhandShuffle(Deck* deck) {
        if (deck -> length == 0) {
                perror("Deck is empty!");
                exit(0);
        }

        srand(time(0));

        int third = (deck -> length) / 3;

        int temp[52] = {-1};
        int numTransferred = 0;
        int inProgress;
        int transferSize;

        while (numTransferred < deck -> length) {
                // transfer somewhere around a third of the deck, as would be normal for an overhand shuffle
                transferSize = third + (rand() % 8 - 4);

                // make sure we don't try to transfer more cards than are in the deck.
                // this sets transferSize to be the minimum of the random number we generated and the deck size - the number of cards already transferred
                transferSize = (transferSize < (deck -> length) - numTransferred) ? transferSize : ((deck -> length) - numTransferred);
                inProgress = transferSize;

                while (inProgress > 0 && numTransferred + (transferSize - inProgress) < deck -> length) {
                        printf("copying deck[%d] = %d to temp[%d]\n", (deck -> length) - numTransferred - inProgress, deck -> cards[(deck -> length) - numTransferred - inProgress], numTransferred + (transferSize - inProgress));
                        temp[numTransferred + (transferSize - inProgress)] = deck -> cards[(deck -> length) - numTransferred - inProgress];

                        inProgress -= 1;
                }

                numTransferred += transferSize;
        }

        for (int i = 0; i < numTransferred; i++) {
                deck -> cards[i] = temp[i];
        }

}


void riffleShuffle(Deck* deck) {
        if (deck -> length == 0) {
                perror("Deck is empty!");
                exit(0);
        }

        srand(time(0));

        // get left and right half of the deck
        int cards[2][26];

        int leftLength = (deck -> length / 2) + (rand() % 8 - 4); // split the deck ± 4 cards
        int rightLength = deck -> length - rightLength;

        for (int i = 0; i < leftLength; i++) {
                cards[0][i] = deck -> cards[i];
        }
        for (int i = 0; i < rightLength; i++) {
                cards[1][i] = deck -> cards[leftLength + i];
        }

        // flag for which side to transfer from
        int side = 0;

        int numTransferred = 0;

        // transfer the cards back to the deck
        while (numTransferred < deck -> length) {
                int transferSize = rand() % 3; // transfer up to 2 cards
                
                while (transferSize > 0 && numTransferred < deck -> length) {
                        
                }
        }

}


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
        for (int i = 0; i < (deck -> length); i++) {
                char card[10];
                cardToString(card, 10, deck -> cards[i]);
                printf("%s, ", card);
        }
        printf("\n");
}
