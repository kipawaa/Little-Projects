#include <stdio.h>
#include <stdlib.h>

// sorts an array of size len using counting sort
void countingSort(int *arr, int len) {
	// determine the range of the data to create the counts array
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	
	int range = max - min;

	int *counts = (int *)calloc(range, sizeof(int));
	int *sorted = (int *)malloc(len * sizeof(int));
	
	// add one to counts at index [the value of arr[i]] for every value in arr
	for (int i = 0; i < len; i++) {
		counts[arr[i] - min]++;
	}

	// for all the numbers in counts, add the value of that index into sorted
	int numSorted = 0;
	for (int i = 0; i < range + 1; i++) {
		while (counts[i] > 0) {
			sorted[numSorted] = i + min;
			counts[i]--;
			numSorted++;
		}
	}
	for (int i = 0; i < len; i++) {
		arr[i] = sorted[i];
	}
}
