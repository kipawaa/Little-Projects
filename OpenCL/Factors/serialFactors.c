#include<stdio.h>
#include<stdlib.h>

int main() {
	int num;
	printf("input a number to find factors: ");
	scanf("%d", &num);
	
	int* factors = (int*)calloc(num, sizeof(int));
	
	for (int iterations = 0; iterations < 1000; iterations++) {
		for (int i = 0; i < num; i++) {
			if (i && !(num % i)) {
				factors[i] = 1;
			}
		}
	}
	printf("complete.\n");
	free(factors);
}
