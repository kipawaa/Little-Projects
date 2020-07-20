#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// defines nodes for use in linked list structure
typedef struct Node {
	int value;
	struct Node *next;
} node;

// defines linked list which uses the node structure
typedef struct LinkedList {
	node *head;
} linkedList;

// allows printing a linked list
void printList(linkedList *list) {
	if (list -> head != NULL){
		node *current = list -> head;
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
linkedList* makeList() {
	linkedList* newList = NULL; 
	newList = (linkedList*)calloc(1, sizeof(linkedList));
	newList -> head = NULL;
	return newList;
}

// allows adding elements to the start of a linked list
void insertStart(int value, linkedList *list) {
	// declares a new pointer for the new node
	node *newNode = NULL;
	newNode = (node *)calloc(1, sizeof(node));
	
	// updates the values of the node
	newNode -> value = value;
	if (list -> head != NULL) {
		newNode -> next = list -> head;
	}

	// makes head point to the new node
	list -> head = newNode;
}

// allows adding elements to the end of a linked list
void insertEnd(int value, linkedList *list) {
	// declares a new node pointer
	node *newNode = NULL;
	newNode = (node *)calloc(1, sizeof(node));

	// updates the value of the node
	newNode -> value = value;
	
	
	node *current = list -> head;
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
void insertSorted(int value, linkedList *list) {
	// initializes a new node
	node *newNode = NULL;
	newNode = (node *)calloc(1, sizeof(node));
	newNode -> value = value;
	newNode -> next = NULL;
	
	// determines where to place the new node to maintain the sortedness of the list
	if (list -> head == NULL) {
		list -> head = newNode;
	} else if (list -> head -> value > newNode -> value) {
		newNode -> next = list -> head;
		list -> head = newNode;
	} else {
		node *current = list -> head;
		while (current -> next != NULL && current -> next -> value < newNode -> value) {
			current = current -> next;
		}
		node *temp = current -> next;
		current -> next = newNode;
		newNode -> next = temp;
	}
}

// determines if a value is present in a list
bool search(int value, linkedList *list) {
	node *current = list -> head;
	while (current -> value != value && current -> next != NULL) {
		current = current -> next;
	}
	return current-> value == value;
}

// deletes the first item from a list
void removeFirst(linkedList *list) {
	if (list -> head == NULL) {
		printf("the list is already empty.\n");
	} else {
		node *newHead = list -> head -> next;
		free(list -> head);
		list -> head = newHead;
	}
}
// deletes the last item from a list
void removeLast(linkedList *list) {
	if (list -> head == NULL) {
		printf("the list is already empty.\n");
	} else if (list -> head -> next == NULL) {
		free(list -> head -> next);
		list -> head = NULL;
	} else {
		node *current = list -> head;
		while (current -> next -> next != NULL) {
			current = current -> next;
		}
		free(current -> next);
		current -> next = NULL;
	}
}

// deletes the first occurence of a given value from a list
void deleteValue(int value, linkedList *list) {
	if (list -> head -> value == value) {
		removeFirst(list);
	} else{
		node *current = list -> head;
		while (current -> next -> value != value && current -> next != NULL) {
			current = current -> next;
		}
		// tbr = to be removed
		node *tbr = current -> next;
		current -> next = current -> next -> next;
		free(tbr);
	}
}

// making a new list doesn't use more memory because you're just sorting pointers

int main() {
	linkedList *newlist = makeList();
	
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
}
