from math import sqrt, ceil
from time import time

def check_prime(num:int) -> bool:
	# primes must be positive
	if num <= 0: return False

	# all numbers less than 3 and greater than 0 are prime are prime
	if num < 3: return True

	# only ever need to check up to the square root of a value
	limit = ceil(sqrt(num))

	# if our number is divisible by any number from 2 to it's root, it's not prime
	for i in range(2, limit+1):
		if num%i == 0:
			return False
	
	# if it's not divisible by any of those, then it IS prime!
	return True

if __name__ == '__main__':
	lim = int(input("find all primes up to: "))
	for i in range(1, lim):
		if check_prime(i): print(i)
