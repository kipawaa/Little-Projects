#include<stdio.h>
#include<stdlib.h>

typedef struct IntNode {
	int data;
	struct IntNode* next;
} Node;

typedef struct IntStack {
	Node *head;
} Stack;

// pushes data onto the stack given by head
void push(Stack *stack, int data) {
	Node *new = NULL;
	new = (Node *)calloc(1, sizeof(Node));
	new -> data = data;
	new -> next = stack -> head;
	stack -> head = new;
}

// pops top item from stack
void pop(Stack *stack) {
	if (stack -> head == NULL) {
		printf("Cannot pop, stack is already empty.\n");
	} else {
		Node *temp = stack -> head;
		stack -> head = stack -> head -> next;
		free(temp);
	}
}

void printStack(Stack *stack) {
	printf("printing stack...\n");
	if (stack -> head == NULL) {
		printf("stack is empty.\n");
	} else {
		Node *current = stack -> head;
		while (current != NULL) {
			printf("%d\n", current -> data);
			current = current -> next;
		}
	}
}

int main() {
	Stack stack = {NULL};
	push(&stack, 1);
	push(&stack, 2);
	printStack(&stack);
	pop(&stack);
	pop(&stack);
	pop(&stack);
	printStack(&stack);
}
