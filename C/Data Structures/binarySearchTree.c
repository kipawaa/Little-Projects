#include<stdio.h>
#include<stdlib.h>


/* Struct: Node
 **************
 * Int node for a BST.
 *
 * left: pointer to the left branch node
 * right: pointer to the right branch node
 * value: the value of this node
 */
typedef struct IntNode {
	struct IntNode *left;
	struct IntNode *right;
	int value;
} Node;


/* Function: hasValue
 ********************
 * returns 1 if value exists in the BST with root root
 *
 * root: the root of the BST
 * value: the value to be searched for
 */
int hasValue(Node* root, int value) {
	// if the root is null then return false
	if (root == NULL) return 0;

	// if the root has the correct value, return true
	else if (root -> value == value) return 1;

	// if the value is less than the root's value, search the left branch
	else if (value < root -> value) return hasValue(root -> left, value);

	// otherwise search the right branch
	else return hasValue(root -> right, value);
}


/* Function: insert
 ******************
 * inserts value to the BST with root root
 *
 * root: the root of the BST
 * value: the value to be inserted
 */
void insert(Node *root, int value) {
	// if the value already exists then notify the user and return, since we can't have duplicates
	if (hasValue(root, value)) {
		printf("this BST already has that value, and cannot have duplicates.");
		return;
	}

	// if the root is empty then add the value here
	if (root == NULL) {
		Node *new = (Node *)calloc(1, sizeof(Node));
		new -> value = value;
		new -> left = NULL;
		new -> right = NULL;
		root = new;
	} 

	// if the value is less than the root's value then add it to the left branch
	else if (value < root -> value) insert(root -> left, value);

	// otherwise add it to the right branch
	else insert(root -> right, value);
}


/* Function: preOrderPrint
 *************************
 * prints the values of the BST with root root via pre-order traversal.
 *
 * root: the root of the BST
 */
void preOrderPrint(Node* root) {
	// if the tree is empty then return
	if (root == NULL) return;
	
	// print the root
	printf("%d, ", root -> value);

	// print the left branch
	if (root -> left != NULL) preOrderPrint(root -> left);
	
	// print the right branch
	if (root -> right != NULL) preOrderPrint(root -> right);
}


/* Function: inOrderPrint
 ************************
 * prints the values of the BST with root root via in-order traversal
 *
 * root: the root of the BST
 */
void inOrderPrint(Node* root) {
	// if the tree is empty then return
	if (root == NULL) return;

	// print the left branch
	if (root -> left != NULL) inOrderPrint(root -> left);

	// print the root
	printf("%d, ", root -> value);

	// print the right branch
	if (root -> right != NULL) inOrderPrint(root -> right);
}


/* Function: postOrderPrint
 **************************
 * prints the values of the BSGT with root root via post-order traversal
 *
 * root: the root of the BST
 */
void postOrderPrint(Node* root) {
	// if the tree is empty then return
	if (root == NULL) return;

	// print the left branch
	if (root -> left != NULL) postOrderPrint(root -> left);

	// print the right branch
	if (root -> right != NULL) postOrderPrint(root -> right);

	// print the root
	printf("%d, ", root -> value);
}


int main() {
	
}
