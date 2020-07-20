#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// determines if num is prime
int prime(int num) {
	// negatives and 0 are not primes
	if (num <= 0) return 0;
	// 0 < x < 4 -> x is prime
	if (num <= 3) return 1;
	
	// check numbers from 2 to sqrt(num). If any of these divide num, num is not prime
	for (int i = 2; i <= (int)sqrt((double)num); i++) {
		if (!(num % i)) return 0;
	}
	
	// if none of those numbers divide num, then num IS prime!
	return 1;
}

void getFactors() {
	printf("find all factors of:\n");
	int num;
	scanf("%d", &num);

	printf("working hard to find you the factors...\n");

	for (int i = 1; i <= num; i++) {
		if (num % i == 0) printf("%d divides %d\n", i, num);
	}

	printf("those are all the factors :)\n");
}

// asks user for a limit and then finds primes up to and including that limit
void getPrimes() {
	// starting prints and ask for limit
	printf("find all primes up to and including:\n");
	int input;
	scanf("%d", &input);
	
	// notify user that we're finding the primes
	printf("finding primes :)\n");

	// gotta find them all!
	for (int i = 0; i <= input; i++) {
		if (prime(i)) printf("%d\n", i);
	}

	// let user know we're finished finding them
	printf("there they are! :D\n");
}

void getPrimeFactors() {
	printf("find prime factors of:\n");
	int num;
	scanf("%d", &num);

	printf("finding prime factors!\n");
	for (int i = 1; i <= (int)sqrt((double)num); i++) {
		if (num % i == 0 && prime(i)) printf("%d is a prime factor of %d\n", i, num);
	}
	printf("those are all the prime factors of %d!\n", num);
}

void prime_factors(int num) {
	for (int i = 0; i < num; i++) {
		printf("%d is a prime factor of %d\n", i , num);
	}
}

int main() {
	getPrimes();
	getFactors();
	getPrimeFactors();
}
