/***
Just a regular fibonacci number calculator. Input the desired term number
'n' into the fib function to have it return the nth fibonacci number
***/
#include<stdio.h>

int fib(int n) {
	if (n < 3) {
		return n;
	} else {
		int x = 1;
		int y = 1;
		int i = 3;
		while (i < n) {
			int temp = x;
			x = y + temp;
			y = temp;
			i ++;
		}
		return x;
	}
}

int main() {
	int n = 0;
	while (1) {
		printf("The %dth term of the fibonacci sequence is %d\n", n, fib(n));
		n++;
	}
}