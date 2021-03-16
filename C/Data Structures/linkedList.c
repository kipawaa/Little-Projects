#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// defines Nodes for use in linked list structure
typedef struct Node {
	int value;
	struct Node *next;
} Node;

// defines linked list which uses the Node structure
typedef struct LinkedList {
	Node *head;
} LinkedList;

// allows printing a linked list
void printList(LinkedList *list) {
	if (list -> head != NULL){
		Node *current = list -> head;
		printf("%d, ", current -> value);
		while (current -> next != NULL) {
			current = current -> next;
			printf("%d, ", current -> value);
		}
		printf("\n");
	 } else {
	 	printf("The list is empty\n");
	}
}


// allows initialization of a linked list
LinkedList* makeList() {
	LinkedList* newList = NULL; 
	newList = (LinkedList*)calloc(1, sizeof(LinkedList));
	newList -> head = NULL;
	return newList;
}

// allows adding elements to the start of a linked list
void insertStart(int value, LinkedList *list) {
	// declares a new pointer for the new Node
	Node *newNode = NULL;
	newNode = (Node *)calloc(1, sizeof(Node));
	
	// updates the values of the Node
	newNode -> value = value;
	if (list -> head != NULL) {
		newNode -> next = list -> head;
	}

	// makes head point to the new Node
	list -> head = newNode;
}

// allows adding elements to the end of a linked list
void insertEnd(int value, LinkedList *list) {
	// declares a new Node pointer
	Node *newNode = NULL;
	newNode = (Node *)calloc(1, sizeof(Node));

	// updates the value of the Node
	newNode -> value = value;
	
	
	Node *current = list -> head;
	if (current == NULL) {
		list -> head = newNode;
	} else {
		// traverses the list until current points to the last value
		while (current -> next != NULL) {
			current = current -> next;
		}
		current -> next = newNode;
	}
}

// allows inserting into sorted list TODO
void insertSorted(int value, LinkedList *list) {
	// initializes a new Node
	Node *newNode = NULL;
	newNode = (Node *)calloc(1, sizeof(Node));
	newNode -> value = value;
	newNode -> next = NULL;
	
	// determines where to place the new Node to maintain the sortedness of the list
	if (list -> head == NULL) list -> head = newNode;
	else if (list -> head -> value > newNode -> value) {
		newNode -> next = list -> head;
		list -> head = newNode;
	} else {
		Node *current = list -> head;
		while (current -> next != NULL && current -> next -> value < newNode -> value) {
			current = current -> next;
		}
		Node *temp = current -> next;
		current -> next = newNode;
		newNode -> next = temp;
	}
}

// determines if a value is present in a list
bool search(int value, LinkedList *list) {
	Node *current = list -> head;
	while (current -> value != value && current -> next != NULL) {
		current = current -> next;
	}
	return current-> value == value;
}

// deletes the first item from a list
void removeFirst(LinkedList *list) {
	if (list -> head == NULL) printf("the list is already empty.\n");
	else {
		Node *newHead = list -> head -> next;
		free(list -> head);
		list -> head = newHead;
	}
}
// deletes the last item from a list
void removeLast(LinkedList *list) {
	if (list -> head == NULL) printf("the list is already empty.\n");
	else if (list -> head -> next == NULL) {
		free(list -> head -> next);
		list -> head = NULL;
	} else {
		Node *current = list -> head;
		while (current -> next -> next != NULL) {
			current = current -> next;
		}
		free(current -> next);
		current -> next = NULL;
	}
}

// deletes the first occurence of a given value from a list
void deleteValue(int value, LinkedList *list) {
	if (list -> head -> value == value) {
		removeFirst(list);
	} else {
		Node *current = list -> head;
		while (current -> next -> value != value && current -> next != NULL) {
			current = current -> next;
		}
		// tbr = to be removed
		Node *tbr = current -> next;
		current -> next = current -> next -> next;
		free(tbr);
	}
}

// find lowest value
int getLeastValue(LinkedList* list) {
	// empty list
	if (list -> head == NULL) return 0;

	int leastValue = list -> head -> value;
	Node* current = list -> head;
	while (current -> next != NULL) {
		current = current -> next;
		if (current -> value < leastValue) leastValue = current -> value;
	}

	return leastValue;
}


void deleteList(LinkedList* list) {
        Node* current = list -> head;
        while (current) {
                Node* temp = current;
                current = current -> next;
                free(temp);
        }
        list -> head = NULL;
}


int main() {
	LinkedList *newlist = makeList();
	
	// insert random numbers to ensure insertSorted works
	insertSorted(9, newlist);
	insertSorted(5, newlist);
	insertSorted(5, newlist);
	insertSorted(3, newlist);
	insertSorted(4, newlist);
	insertSorted(1, newlist);
	insertSorted(3, newlist);
	insertSorted(5, newlist);
	insertSorted(8, newlist);

	printList(newlist);

        deleteList(newlist);

        // check for memory leaks
        system("leaks a.out\n");
}
