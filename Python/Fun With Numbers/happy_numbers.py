def isHappy(num:int, maxLoops:int=995, numLoops:int = 0):
    n = sum([int(digit)**2 for digit in str(num)])
    if n == 1:
        return True
    elif numLoops > maxLoops:
        return False
    else:
        return isHappy(n, maxLoops, numLoops+1)

if __name__ == '__main__':
	n = int(input("input a number to determine its happiness (or 0 to quit): "))
	while n != 0:
		print(isHappy(n))
		n = int(input("input another number to determine its happiness (or 0 to quit): "))
