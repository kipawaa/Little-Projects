#include<stdio.h>
#include<stdlib.h>

typedef struct IntNode {
	int data;
	struct IntNode *left;
	struct IntNode *right;
} Node;

void insert(Node *head, int data) {	
	if (head == NULL) {
		Node *new = (Node *)calloc(1, sizeof(Node));
		new -> data = data;
		new -> left = NULL;
		new -> right = NULL;
		head = new;
	} else {
		if (data < head) {
			insert(head -> left, data);
		else {
			insert(head -> right, data);
		}
	}
}

bool find(Node *head, int value) {
	if (head == NULL) {
		return false;
	} else if (head -> data == value) {
		return true;
	} else {
		if (value < head -> data) {
			find(head -> left, data);
		} else {
			find(head -> right, data);
		}
	}
}

int main() {
	Node tree = NULL;
	insert
}
