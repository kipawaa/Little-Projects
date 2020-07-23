#include<stdio.h>
#include<stdlib.h>

// take an array, arr, and its length, len, and applies insertion sort, a relatively quick O(n^2) sort
void insertionSort(int* arr, int len) {
	// loop through all elements in the array
	for (int i = 0; i < len; i++) {
		int j = i;
		// starting at the current element, move the current element backwards until you reach the start of the array or a smaller element
		while (j > 0 && arr[j] < arr[j-1]) {
			int temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;
			j--;
		}
	}
}
