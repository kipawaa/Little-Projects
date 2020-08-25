from prime_factors import get_prime_factors

def product(lst):
	total = 1
	for i in lst:
		total *= i
	return total

def prime_decomposition(n):
	factors = get_prime_factors(n)
	
	while product(factors) < n:
		newFactors = get_prime_factors(n // product(factors))
		factors.extend(newFactors[1:])
	
	factors.sort()
	
	return factors

if __name__ == '__main__':
	for i in range(1, 1000):
		decomp = prime_decomposition(i)
		print(product(decomp), decomp)
