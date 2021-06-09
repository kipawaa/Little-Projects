/* Deck.h
 **************
 * This file implements a queue using an array.
 * An array is used to improve lookup, enqueue and dequeue times over a linked list.
 * modular arithmetic is used to make enqueue and dequeue more efficient.
 * to achieve this, we store length and index.
 * length represents the number of data entries currently in the queue
 * index represents the current start of the queue.
 * When an item is dequeued, it is removed from the array at index index
 * index is then incremented, and the "start" of the queue is now the next element in the array
 * Deqing is done by removing the item at index length
 * length is then decremented
 * modular arithmetic is used to ensure that both length and index remain valid indices
 * this achieves O(1) enqueue, O(1) dequeue
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/* Struct: Deck
 ***************
 * Queue structure for storing a deck of cards
 */
typedef struct ArrayQueue {
        int length; // how many cards are currently in the Deck
        int index; // current index of the first Card in the Deck
        int cards[53]; // stores the Card data as integers (need 53 to have a gap for the queue)
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


/* Function: printDeck
 *********************
 * prints the cards in the deck in order
 */
void printDeck(Deck* deck);
