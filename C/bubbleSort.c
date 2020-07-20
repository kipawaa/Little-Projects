#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void bubbleSort(int arr[SIZE]) {
	for (int j = 0; j < SIZE; j++) {
		for (int i = 0; i < SIZE - 1; i++) {
			if (arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
}

void printArr(int arr[SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		printf("%d\n", arr[i]);
	}
}

int main() {
	int arr[SIZE] = {1, 4, 6, 7, 9, 5, 3, 4, 5, 6};
	printf("pre-sort:\n");
	printArr(arr);
	bubbleSort(arr);
	printf("post-sort:\n");
	printArr(arr);
}
