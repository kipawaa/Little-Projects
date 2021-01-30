#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"isPrime.h"

// allows the user to input a number and prints all of the factors of that number
void getFactors(int num) {
	// since large numbers can take a while, informs the user that the program is working
	printf("working hard to find you the factors of %d...\n", num);

	// determines the factors of the number
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) printf("%d\n", i);
	}

	// notifies the user that all the factors have been found :)
	printf("those are all the factors!\n");
}

// allows the user to input a number and returns all prime factors of that number
void getPrimeFactors(int num) {
	// notifies the user that the program is working
	printf("finding prime factors!...\n");

	// determines the prime factors of the number and prints them
	for (int i = 1; i <= (int)sqrt((double)num); i++) {
		if (num % i == 0 && isPrime(i)) printf("%d\n", i);
	}

	// notifies the user that all the primes factors have been found
	printf("those are all the prime factors of %d!\n", num);
}

int main() {
	int num = 0;
	printf("input a number to find the factors and prime factors:");
	scanf("%d", &num);
	
	getFactors(num);
	getPrimeFactors(num);
}
