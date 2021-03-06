/***
This program contains a series of functions that can determine primality, the factors of a number, and the prime factors of a number.
 ***/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// returns 1 if num is prime, 0 otherwise
int isPrime(int num) {
	// negatives and 0 are not primes
	if (num <= 0) return 0;
	// 0 < x < 4  ->  x is prime
	if (num <= 3) return 1;
	
	// check numbers from 2 to sqrt(num). If any of these divide num, num is not prime
	for (int i = 2; i <= (int)sqrt((double)num); i++) {
		if (!(num % i)) return 0;
	}
	
	// if none of those numbers divide num, then num IS prime!
	return 1;
}

// asks user for a limit and then finds primes up to and including that limit
void getPrimes() {
	// asks the user for the limit
	printf("find all primes up to and including:\n");
	int input;
	scanf("%d", &input);
	
	// notify user that we're finding the primes
	printf("finding primes...\n");

	// finds all the primes
	for (int i = 0; i <= input; i++) {
		if (isPrime(i)) printf("%d\n", i);
	}

	// let user know we're finished finding the primes
	printf("that's all of 'em!\n");
}

int main() {
	getPrimes();
}
