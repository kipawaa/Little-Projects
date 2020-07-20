# recursive algorithm for factorial number generation

def getFactorial(num:int) -> int:
    if num == 1:
        return 1
    else:
        return num*getFactorial(num-1)

if __name__ == '__main__':
	print(getFactorial(100));
