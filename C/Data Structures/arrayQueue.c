/* arrayQueue.c
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
#include<limits.h>


/* Struct: Queue
 ***************
 * Queue structure with length, index and data members
 */
typedef struct ArrayQueue {
        int maxSize; // maximum size of the queue (length of the array)
        int length; // current length of the queue
        int index; // current index of the first element of the queue
        int* data; // stores the data
} Queue;


/* Function: getQueue
 ********************
 * initializes a new q and returns a pointer to it
 */
Queue* getQueue(int maxSize) {
        maxSize += 1; // need one extra space to prevent index and length from overlapping when full

        // get queue
        Queue* q = (Queue*)calloc(1, sizeof(Queue));
        
        // initialize values
        q -> maxSize = maxSize;
        q -> length = 0;
        q -> index = 0;
        q -> data = (int*)calloc(maxSize, sizeof(int));
        
        // return
        return q;
}


/* Function: enqueue
 *******************
 * takes a pointer to a queue and an integer value, then enqueues the value
 */
void enqueue(Queue* q, int val) {
        // makes sure that the array has space
        // the expression on the right will return index - 1 if the index is above zero
        // otherwise it will return the length of the array -1 (effectively the space before 0, since it wraps around)
        // notice that we use maxSize - 1 because we require a one space gap between index and length to distinguish
        //      between empty and full
        if (q -> length == ((q -> index) > 0 ? (q -> index - 1) : (q -> maxSize - 1))) {
                printf("I'm full!\n");
                return;
        }

        q -> data[q -> length] = val;
        q -> length = (q -> length) < (q -> maxSize - 1) ? (q -> length + 1) : 0;
}


/* Function: dequeue
 *******************
 * takes a pointer to a queue and dequeues a value
 */
int dequeue(Queue* q) {
        if (q -> length == q -> index) {
                printf("I'm empty!!!\n");
                return INT_MIN;
        }
        int temp = q -> data[q -> index];
        q -> index = (q -> index) < (q -> maxSize - 1) ? (q -> index + 1) : 0;
        return temp;
}


void printQueue(Queue* q) {
        int i = 0;
        while ((q -> index + i) % (q -> maxSize) != (q -> length)) {
                printf("%d ", q -> data[q -> index + i]);
                i++;
        }
        printf("\n");

}


int main() {
        Queue* q = getQueue(10);
        printQueue(q);
        for (int i = 0; i < 10; i++) {
                enqueue(q, i);
        }

        printf("should print values 0-9:\n");
        printQueue(q);
        printf("\n");
        
        printf("should give an error for overfilling\n");
        enqueue(q, 9);
        printf("\n");

        printf("should print the values 0-9:\n");
        printQueue(q);
        printf("\n");

        
        printf("should print values 0-9 and then errors for removing from empty:\n");
        for (int i = 0; i < 15; i++) {
                printf("%d ", dequeue(q));
        }
        printf("\n");

}
