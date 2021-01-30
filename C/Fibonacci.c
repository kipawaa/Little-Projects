/***
Just a regular fibonacci number calculator. Input the desired term number
'n' into the fib function to have it return the nth fibonacci number
***/
#include<stdio.h>

int fib(int n) {
	// determines the 'n'th fibonacci number
	if (n == 0) return 0;
	int x = 0;
	int y = 1;

	for (int i = 1; i < n; i++) {
		if (x < y) x += y;
		else y += x;
	}

	if (x > y) return x;
	else return y;
}

int main() {
	int l = 0;
	printf("input the number of fibonacci terms you'd like: ");
	scanf("%d", &l);

	for (int n = 0; n < l; n++) {
		printf("The %dth term of the fibonacci sequence is %d\n", n, fib(n));
	}
}
