// merge sort program. Takes an array, the index of the leftmost and rightmost elements, and the length and applies merge sort, an O(n * log(n)) sort
#include<stdio.h>
#include<stdlib.h>

// merge function for use with mergeSort
void merge(int* arr, int len, int left, int middle, int right) {
	// determine the number of elements present in each "half" of the array
	int llimit = middle - left + 1;
	int rlimit = right - middle;

	// create arrays using those sizes to store sorted data
	int leftSide[llimit];
	int rightSide[rlimit];
	
	// copy data from each half of the array to the newly created arrays
	for (int i = 0; i < llimit; i++) {
		leftSide[i] = arr[left+i];
	}
	for (int i = 0; i < rlimit; i++) {
		rightSide[i] = arr[middle+1+i];
	}
	
	// starting indexes for sorting data
	int l = 0;
	int r = 0;
	int i = left;
	
	// until one half is depleted, add the smallest value from either array to the original array
	while (l < llimit && r < rlimit) {
		if (leftSide[l] < rightSide[r]) {
			arr[i] = leftSide[l];
			i++;
			l++;
		} else {
			arr[i] = rightSide[r];
			i++;
			r++;
		}
	}

	// pick up any remaining values from the left side
	while (l < llimit) {
		arr[i] = leftSide[l];
		l++;
		i++;
	}

	// pick up any remaining values from the right side
	while (r < rlimit) {
		arr[i] = rightSide[r];
		r++;
		i++;
	}
}

void mergeSort(int* arr, int len, int left, int right) {
	if (left < right) {
		// split the array in two
		int middle = left + (right - left)/2;
		
		// merge sort left half
		mergeSort(arr, middle - left, left, middle);
		
		// merge sort right half
		mergeSort(arr, right - middle - 1, middle+1, right);

		// merge the two halves
		merge(arr, len, left, middle, right);
	}
}
