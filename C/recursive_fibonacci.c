#include<stdio.h>

int fib(int n) {
	return (n < 2) ? n : fib(n - 1) + fib(n - 2);
}

int main() {
	int num;
	printf("input the last term desired: ");
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		printf("the value of the %dth term is %d\n", i, fib(i)); 		;
	}
}
