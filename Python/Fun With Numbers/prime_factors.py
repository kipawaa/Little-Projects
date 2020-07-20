from math import ceil
from factors import get_factors
from primes import check_prime

def get_prime_factors(num):
    factors = get_factors(num)
    prime_factors = []
    for factor in factors:
        if check_prime(factor):
            prime_factors.append(factor)
    return prime_factors

if __name__ == '__main__':
	term_number = int(input("input a number to find prime factors of: "))
	print(get_prime_factors(term_number))
