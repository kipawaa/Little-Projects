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
        Queue* q = (Queue*)calloc(1, sizeof(Queue));
        q -> maxSize = maxSize;
        q -> length = 0;
        q -> index = 0;
        q -> data = (int*)calloc(maxSize, sizeof(int));
        return q;
}


/* Function: enq
 *******************
 * takes a pointer to a queue and an integer value, then enqueues the value
 */
void enqueue(Queue* q, int val) {
        if (q -> index == q -> length) {
                printf("too big!\n");
                return;
        }

        q -> data[q -> length] = val;
        q -> length = (q -> length) < (q -> maxSize - 1) ? (q -> length + 1) : 0;
}


/* Function: deq
 *******************
 * takes a pointer to a queue and dequeues a value
 */
int dequeue(Queue* q) {
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
        enqueue(q, 10);
        enqueue(q, 12);

        printf("should print 10, 12\n");
        printQueue(q);

        enqueue(q, 3);
        printf("should print 10, 12, 3\n");
        printQueue(q);

        dequeue(q);
        printf("should print 12, 3\n");
        printQueue(q);
}
