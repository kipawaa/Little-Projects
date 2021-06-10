#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* Struct: Deck
 ***************
 * Array structure for storing a deck of cards
 */
typedef struct Deck {
        int length; // how many cards are currently in the Deck
        int cards[52]; // stores the Card data as integers (need 53 to have a gap for the queue)
} Deck;


/* Function: newDeck
 *******************
 * returns a new (sorted) Deck of Cards
 */
Deck* newDeck(void);


/* Function: getNext
 *******************
 * returns a pointer to the next card in the deck
 */
int getNext(Deck* deck);


/* Function: overhandShuffle
 ***************************
 * shuffles the deck in a way similar to an overhand shuffle
 */
void overhandShuffle(Deck* deck);


/* Function: cardToString
 ************************
 * copies n bytes of card data to a string in human-readable format (value + suit)
 */
void cardToString(char* string, int numBytes, int card);


/* Function: printDeck
 *********************
 * prints the cards in the deck in order
 */
void printDeck(Deck* deck);







// Functions imported for testing
void addToEnd(Deck* deck, int card);
