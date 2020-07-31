#include<stdio.h>

/*
a few simple examples of branchless programming to help explain the concept and provide reminders

Branchless programming is the idea that if statements can be very slow, since the CPU cannot pre-determine what commands it will have to execute in the coming lines and must choose one of possibly many paths.
The proposed solution is to return a long arithmetic statement using boolean values to have only one path.
*/

// this function can be written this way using if statements
int isOdd(int num) {
	if (num % 2 == 0) {
		return 0; // 0 = false
	} else {
		return 1; // 1 = true
	}
}

// but it can also be written in a branchless way!
int branchlessIsOdd(int num) {
	// there are two ways to do this:

	// the first is the "expanded" branchless form:
	// 	return (num % 2) * 0    +    !(num % 2) * 1;			I've spaced out the two sides of the addition to make it a little bit clearer where each "branch" of the branchless statement is handled
	// note that (num % 2) will evaluate to 1 if the number is even, and 0 if it is odd.
	// also, !(num % 2) will evaluate to 0 if the number is even, and 1 if it is odd.
	// this means that with an even number, we will have 1 * 0    +    0 * 1
	// and with an odd number we will have 0 * 0   +   1 * 1

	// but since the first half will always be multiplied by 0, and the second half always by one, we can reduce the statement to the following:
	return !(num % 2);
}
// this might be confusing, since you're already familiar with this example so you have pre-existing ideas in your head about it, and because it reduces down so much that it feels redundant in expanded form


// here's another example that should be easier to follow:
int collatzStep(int num) {
	// the collatz conjecture suggets than the following process will eventually return 1 given any positive input integer if repeated enough times
	// if the number is even, divide by two
	// if the number is odd, multiply by three and add one
	// this can be done normally like this:
	if (num % 2 == 0) {
		return num / 2;
	} else {
		return num * 3 + 1;
	}
}

// that code has a branch! Here's how we can get rid of that branch:

int branchlessCollatzStep(int num) {
		// !(num % 2) this will be true if num % 2 returns 0 which occurs only when num is even. Similar logic applies to the second statement
	return !(num % 2) * (num / 2)   +   (num % 2) * (num * 3 + 1);
	// note that with this statement we still use the boolean statement that were used in the if statements above, 
	//but this method gives the CPU no choice on what to do, since there's only one statement here to execute!
}

int main() {
	// if you want to see some outputs from these functions, run this code! 
	// They produce the same numbers, but the branchless methods will *generally* be faster 
	// (occasionally with simple/common statements the compiler will recognize it and translate to a branchless statement for optimization automatically)

	printf("comparing the two isOdd functions:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d from the branched solution, %d from the branchless solution :)\n", isOdd(i), branchlessIsOdd(i));
	}

	printf("\n comparing the two collatzStep functions:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d from the branched solution, %d from the branchless solution :)\n", collatzStep(i), branchlessCollatzStep(i));
	}
}
