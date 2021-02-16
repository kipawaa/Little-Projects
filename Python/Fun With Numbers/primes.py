from math import sqrt, floor
from time import time

# list for memoization
saved = [2, 3]

def is_prime(num):
	# primes must be positive
	if num <= 1: return False

	# all numbers less than 3 and greater than 0 are prime are prime
	if num < 3: return True

	# if its in our saved primes list we don't need to calculate it
	if num in saved: return True

	# only ever need to check up to the square root of a value
	limit = floor(sqrt(num))

	# if our number is divisible by any number from 2 to it's root, it's not prime
	for i in range(2, limit + 1):
		if num % i == 0:
			return False
	
	# if it's not divisible by any of those, then it IS prime!
	return True

if __name__ == '__main__':
    mode = int(input("choose a mode:\nbatch mode: 0\nsingle mode: 1\n"))
    
    """ batch mode """
    if mode == 0:
        start = int(input("input the start number: "))
        end = int(input("input the end number: "))
        
        for i in range(start, end + 1):
            if is_prime(i): print(f"{i} is prime!")
            else: print(f"{i} is not prime")

    if mode == 1:
        num = 1
        while num >= 0:
            num = int(input("input a number (or -1 to quit): "))
            if is_prime(num): print(f"{num} is prime!")
            else: print(f"{num} is not prime")
