from math import ceil
from factors import get_factors
from primes import check_prime

def get_prime_factors(num):
    return [factor for factor in get_factors(num) if check_prime(factor)]

if __name__ == '__main__':
	term_number = int(input("input a number to find prime factors of: "))
	print(get_prime_factors(term_number))
