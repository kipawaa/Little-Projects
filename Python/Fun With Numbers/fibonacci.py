# Return the nth term of the fibonacci sequence, with the sequence starting: 0, 1, 1, 2...

# dictionary for memoization
dictionary = {1: 0, 2: 1}

# memoized fibonacci calculator
def memoized_fibonacci(n:int) -> int:
	# returns if the term of interest is in the dictionary, otherwise recursively calculates it
	if n in dictionary:
		return dictionary[n]
	else:
		a = memoized_fibonacci(n-1) + memoized_fibonacci(n-2)
		# updates the dictionary
		dictionary[n] = a

		# returns the value
		return a

if __name__ == '__main__':
    mode = int(input("choose a mode:\nbatch mode: 0\nsingle mode: 1\n"))
    
    """ batch mode """
    if mode == 0:
        start = max(int(input("input the start number (n > 0): ")), 1)
        end = int(input("input the end number: "))
        
        for i in range(start, end + 1):
            print(f"the {i}th fibonacci number is: {memoized_fibonacci(i)}")

    if mode == 1:
        num = 1
        while num > 0:
            num = int(input("input a number (n > 0) (or -1 to quit): "))
            if num > 0: print(f"the {num} fibonacci number is: {memoized_fibonacci(num)}")

