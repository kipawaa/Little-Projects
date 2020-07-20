from factors import get_prime_factors

def prime_decomposition(n):
	factors = get_prime_factors(n)
	product = 1
	
	for i in factors:
		product *= i

	if product < n:
		factors.append(i for i in get_prime_factors(n/product))
	return factors

if __name__ == '__main__':
	for i in range(2, 100):
		print(prime_decomposition(i))
	
