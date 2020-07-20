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
