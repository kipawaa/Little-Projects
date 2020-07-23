// Bubble Sort

#include<stdio.h>
#include<stdlib.h>

// imports my printArr function from the directory
#include"printArr.c"

// takes a pointer to an array, arr, and the length of that array, len, and applies bubble sort: an O(n^2) sorting algorithm
void bubbleSort(int* arr, int len) {
	// starting at the first index and working to the last, 
	for (int j = 0; j < len; j++) {
		for (int i = 0; i < len - 1; i++) {
			if (arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
}

int main() {
	int len = 10;
	int arr[10] = {1, 4, 6, 7, 9, 5, 3, 4, 5, 6};
	printf("pre-sort:\n");
	printArr(arr, len);
	bubbleSort(arr, len);
	printf("post-sort:\n");
	printArr(arr, len);
}
