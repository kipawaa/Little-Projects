def get_factors(num):
	return [i for i in range(1, num + 1) if num % i == 0]

if __name__ == '__main__':
	for i in range(1, 10):
		print(str(i) + ": " + str(get_factors(i)))
