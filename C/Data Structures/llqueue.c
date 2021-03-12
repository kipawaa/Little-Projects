#include<stdio.h>
#include<stdlib.h>

typedef struct IntNode {
	int data;
	struct IntNode *next;
} Node;

typedef struct IntQueue {
	Node *first;
	Node *last;
} Queue;

void enqueue(Queue *queue, int data) {
	// intializes a new node
	Node *new = NULL;
	new = (Node *)calloc(1, sizeof(Node));
	new -> data = data;
	
	// places the new node in the queue
		// if the queue is empty, set first and last equal to the new element
	if (queue -> last == NULL) {
		queue -> first = new;
		queue -> last = new;
	} else {
		// otherwise, link the new value to the list and set last equal to the new value
		queue -> last -> next = new;
		queue -> last = new;
	}
}

void dequeue(Queue *queue) {
	if (queue -> first == NULL) {
		printf("Cannot dequeue, queue is already empty.\n");
	} else {
		Node *temp = queue -> first;
		queue -> first = queue -> first -> next;
		free(temp);
	}
}

void printQueue(Queue *queue) {
	printf("Printing queue...\n");
	if (queue -> first == NULL) {
		printf("Queue is empty.\n");
	} else {
		Node *current = queue -> first;
		while (current != NULL) {
			printf("%d\n", current -> data);
			current = current -> next;
		}
	}
}

int main() {
	Queue queue = {NULL, NULL};
	printf("created\n");
	enqueue(&queue, 1);
	enqueue(&queue, 2);
	printQueue(&queue);
	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);
	printQueue(&queue);
}
