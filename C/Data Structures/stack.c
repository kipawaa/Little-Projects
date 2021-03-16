#include<stdio.h>
#include<stdlib.h>

typedef struct IntNode {
	int data;
	struct IntNode* next;
} Node;

typedef struct IntStack {
	Node *head;
} Stack;


Stack* getStack() {
        Stack* stack = (Stack*)calloc(1, sizeof(Stack));
        stack -> head = NULL;
        
        return stack;
}


void push(Stack* stack, int data) {
	Node *new = (Node *)calloc(1, sizeof(Node));
	new -> data = data;
	new -> next = stack -> head;
	stack -> head = new;
}


void pop(Stack* stack) {
	if (stack -> head == NULL) {
		printf("Cannot pop, stack is already empty.\n");
                return;
	}

        Node *temp = stack -> head;
	stack -> head = stack -> head -> next;
	free(temp);
	
}


void deleteStack(Stack* stack) {
        Node* current = stack -> head;

        while (current) {
                Node* temp = current;
                current = current -> next;
                free(temp);
        }

        stack -> head = NULL;
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
	Stack* stack = getStack();
	push(stack, 1);
	push(stack, 2);
	printStack(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	printStack(stack);

        deleteStack(stack);
        
        // check for memory leaks
        system("leaks a.out\n");
}
