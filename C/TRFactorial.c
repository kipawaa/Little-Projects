/***
 This is a tail recursive factorial function. 
 Tail recursion calls the function only from within the return statement, 
 meaning that the stack will never overflow and the function can be called essentially limitlessly. 
 This is impractical for a factorial function in C, 
 since the integers will overflow long before the stack, 
 but it's any easy way to get a feel for tail recursion.
 ***/

#include<stdio.h>
#include<stdlib.h>

int TRFactorial(int num, int sum) {
	if (num <= 1) {
		return sum;
	} else {
		return TRFactorial(num - 1, num * sum);
	}
	return 1;
}

int main() {
	printf("starting!\n");
	for (int i = 0; i < 25; i++) {
		int sum = TRFactorial(i, 1);
		printf("%d! = %d\n", i, sum); 
	}
	printf("that's all folks!\n");
}
