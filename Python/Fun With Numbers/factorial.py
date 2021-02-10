# recursive algorithm for factorial number generation

def getFactorial(num:int) -> int:
	return 1 if num == 1 else num * getFactorial(num - 1)

if __name__ == '__main__':
	end = int(input("input a number to factorial:"))
	for i in range(1, end + 1):
		print(str(i) + ": " + str(getFactorial(i)))
