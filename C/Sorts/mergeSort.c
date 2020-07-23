#include<stdio.h>
#include<stdlib.h>

void merge(int* arr, int len, int left, int middle, int right) {
	int llimit = middle - left + 1;
	int rlimit = right - middle;
	int leftSide[llimit];
	int rightSide[rlimit];

	for (int i = 0; i < llimit; i++) {
		leftSide[i] = arr[left+i];
	}
	for (int i = 0; i < rlimit; i++) {
		rightSide[i] = arr[middle+1+i];
	}

	int l = 0;
	int r = 0;
	int i = left;
	
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
	while (l < llimit) {
		arr[i] = leftSide[l];
		l++;
		i++;
	}
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
