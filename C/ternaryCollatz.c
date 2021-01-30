#include<stdio.h>
#include<stdlib.h>

int getCollatz(int num, int count) {
	if (num == 1) return count;
	else return (num % 2) ? getCollatz(num * 3 + 1, count + 1) : getCollatz(num / 2, count + 1);
}

int main() {
	int num = 0;
	printf("enter a number: ");
	scanf("%d", &num);
	
	for (int n = 1; n < num; n++) {
		printf("%d has collatz number %d\n", n, getCollatz(n, 0));
	}
}
