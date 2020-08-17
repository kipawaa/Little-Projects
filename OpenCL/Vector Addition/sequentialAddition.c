#include<stdlib.h>
#include<stdio.h>

#define arrSize 1000000

void vectorAddition(int* a, int* b, int* c) {
	for (int i = 0; i < arrSize; i++) {
		c[i] = a[i] + b[i];
	}
}

int main() {
	int* a = (int*) malloc(arrSize * sizeof(int));
	int* b = (int*) malloc(arrSize * sizeof(int));
	int* c = (int*) malloc(arrSize * sizeof(int));

	for (int i = 0; i < arrSize; i++) {
		a[i] = 1;
		b[i] = 1;
	}

	vectorAddition(a, b, c);
	
}
