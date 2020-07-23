/***
This program contains a series of functions that can determine primality, the factors of a number, and the prime factors of a number.
 ***/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// returns 1 if num is prime, 0 otherwise
int prime(int num) {
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

// allows the user to input a number and prints all of the factors of that number
void getFactors() {
	// asks the user which number they would like to find factors of
	printf("find all factors of:\n");
	int num;
	scanf("%d", &num);

	// since large numbers can take a while, informs the user that the program is working
	printf("working hard to find you the factors...\n");

	// determines the factors of the number
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) printf("%d divides %d\n", i, num);
	}

	// notifies the user that all the factors have been found :)
	printf("those are all the factors :)\n");
}

// asks user for a limit and then finds primes up to and including that limit
void getPrimes() {
	// asks the user for the limit
	printf("find all primes up to and including:\n");
	int input;
	scanf("%d", &input);
	
	// notify user that we're finding the primes
	printf("finding primes :)\n");

	// finds all the primes
	for (int i = 0; i <= input; i++) {
		if (prime(i)) printf("%d\n", i);
	}

	// let user know we're finished finding the primes
	printf("there they are! :D\n");
}

// allows the user to input a number and returns all prime factors of that number
void getPrimeFactors() {
	// asks the user which number they would like to find prime factors of
	printf("find prime factors of:\n");
	int num;
	scanf("%d", &num);

	// notifies the user that the program is working
	printf("finding prime factors!...\n");

	// determines the prime factors of the number and prints them
	for (int i = 1; i <= (int)sqrt((double)num); i++) {
		if (num % i == 0 && prime(i)) printf("%d is a prime factor of %d\n", i, num);
	}

	// notifies the user that all the primes factors have been found
	printf("those are all the prime factors of %d!\n", num);
}

int main() {
	getPrimes();
	getFactors();
	getPrimeFactors();
}
