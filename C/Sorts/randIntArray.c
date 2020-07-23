#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"printArr.c"

// returns a pointer to an array of random integers of size 'len', in the range of the limits 'min' and 'max' inclusive
int* randomIntArray(int len, double min, double max) {
	// intializes the array
	int* arr =(int*) calloc(len, sizeof(int));

	// prints and returns null (by later return statement) if the array failed to be calloced
	if (arr == NULL) printf("failed to calloc enough space\n");
	// if calloc was successful, fills the array with random numbers
	else {
		// seeds the random number generator using start time of program
		srand(time(0));
		// fills the array with random numbers
		for (int i = 0; i < len; i++) {
			arr[i] = (int)((double)(rand() + 1)/(double)(RAND_MAX)  * (max + min + 1) - min);
		}
	}
	// returns the pointer to the aray
	return arr;
}

int main() {
	int len = 100;
	int* arr = (int*) calloc(len, sizeof(int));
	arr = randomIntArray(len, 0, 10);
	printArr(arr, len);
}
