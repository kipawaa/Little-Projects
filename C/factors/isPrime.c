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
