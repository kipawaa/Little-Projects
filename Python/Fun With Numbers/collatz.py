# collatz number calculator
# takes user input and determines the collatz number of all integers up to the input number

# determines the collatz number of 'num'
def getCollatz(num:int, numSteps:int=0) -> int:
    if num == 1:
        return numSteps
    else:
    	return getCollatz(num//2, numSteps + 1) if num % 2 == 0 else getCollatz(num * 3 + 1, numSteps + 1)

if __name__ == '__main__':
	# asks for the user to input the endpoint
	end = int(input('input endpoint: '))

	#prints collatz numbers of every integer in range [0, endpoint]
	for i in range(1, end + 1):
    		print(str(i) + ":", getCollatz(i))
