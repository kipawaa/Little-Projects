#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void quickSort(int arr[SIZE]) {
	// choose random pivot

	// sort relative to pivot

	// recurse
}

void printArr(int arr[SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		printf("%d\n", arr[i]);
	}
}

int main() {
	int arr[SIZE] = {1, 3, 5, 7, 4, 3, 5, 7, 4, 2};

	printf("pre-sort:\n");
	printArr(arr);
	quickSort(arr);
	printf("post-sort:\n");
	printArr(arr);
}
