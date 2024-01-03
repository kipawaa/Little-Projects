#include<stdio.h>
#include<stdlib.h>


int collatz(int n) {
        int current = n;
        int numSteps = 0;
        
        // if we reach a number less than the input then that number has been checked, no need to store anything
        while (current >= n) {
                numSteps += 1;
                if (current % 2) current = (3 * current + 1) / 2;
                else current = current / 2;
        }

        return numSteps;
}

int main() {
        int n = 396685373;
        while (n > 1) {
                printf("%d steps for %d\n", collatz(n), n);
                // increase by 2 since any even number will be reduced to an odd case 
                n += 2;
        }
}
