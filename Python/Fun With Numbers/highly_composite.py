from factors import get_factors

def is_highly_composite(num):
	num_factors = len(get_factors(num))
	for i in range(num-1):
		if len(get_factors(i)) >= num_factors:
			return False
	return True

if __name__ == '__main__':
	for i in range(374):
		if is_highly_composite(i):
			print(i, "is highly composite :)")
