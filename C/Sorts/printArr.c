#include<stdio.h>
#include<stdlib.h>

// takes an array, arr, and its length, len, and prints the values within (must be integers)
void printArr(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\n");
}
