# Return the nth term of the fibonacci sequence, with the sequence starting: 0, 1, 1, 2...

# dictionary for memoization
dictionary = {1: 0, 2: 1}

# memoized fibonacci calculator
def memoizedFib(n:int) -> int:
	# returns the term of interest is in the dictionary, otherwise recursively calculates it
	if n in dictionary:
		return dictionary[n]
	else:
		a = memoizedFib(n-1) + memoizedFib(n-2)
		# updates the dictionary
		dictionary[n] = a

		# returns the value
		return a

if __name__ == '__main__':
	# asks the user for a term of interest
	n = int(input('state the term number of interest (0 to quit): '))

	# continues asking the user for more terms until they ask for the 0th term
	while n != 0:
		# prints the value
		print(memoizedFib(n))

		# asks again
		n = int(input('state the term number of interest (0 to quit): '))
