#include <stdio.h>
#include <stdlib.h>

// sorts an array, arr, of size 'len' using counting sort, an O(n) sort. WARNING! Counting sort can be very space in-efficient if the range of the data is large
void countingSort(int *arr, int len) {
	// determine the range of the data to create the counts array
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	
	int range = max - min;
	
	// the counts array stores the number of occurences of each number in the original array its corresponding index (so if there were 3 occurences of the number 2 in the original array, counts[2] = 3)
	int *counts = (int *)calloc(range, sizeof(int));
	// an empty array to store the data once it has been sorted
	int *sorted = (int *)malloc(len * sizeof(int));
	
	// add one to counts at index [the value of arr[i]] for every value in arr
	for (int i = 0; i < len; i++) {
		counts[arr[i] - min]++; // the "- min" ensures that arrays that aren't in the range [0, x] are still stored as efficiently as possible
	}

	// for all the numbers in counts, add the value of that index into sorted
	int numSorted = 0;
	for (int i = 0; i < range + 1; i++) {
		while (counts[i] > 0) {
			sorted[numSorted] = i + min; // the "+ min" accounts for the shifting we applied when adding values to counts
			counts[i]--;
			numSorted++;
		}
	}

	// copies all the sorted data back into the original array
	for (int i = 0; i < len; i++) {
		arr[i] = sorted[i];
	}

        free(counts);
        free(sorted);
}
