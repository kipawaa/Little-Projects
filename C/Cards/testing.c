#include"deck.h"

int main() {
        // test creating a new deck, should print all cards in order
        printf("testing new deck:\n");
        Deck* deck = newDeck();
        printDeck(deck);

        // test getting next card and cardToString
        printf("testing getNext and cardToString:\n");
        char buff[10];
        cardToString(buff, 10, getNext(deck));
        printf("%s\n", buff);
        printDeck(deck);

        // test adding to deck
        printf("testing adding to deck:\n");
        addToEnd(deck, 51);
        printDeck(deck);

        // clear before testing new functions
        free(deck);
        deck = newDeck();

        // test shuffling on a new deck
        printf("testing shuffle with new deck\n");
        overhandShuffle(deck);
        printDeck(deck);

        printf("Testing Complete\n");
}
