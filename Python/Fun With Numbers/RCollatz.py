# collatz number calculator
# takes user input and determines the collatz number of all integers up to the input number

# determines the collatz number of 'num'
def getCollatz(num:int) -> int:
    if num == 1:
        return 1
    else:
        if num%2 == 0:
            return getCollatz(num//2)
        else:
            return getCollatz(num*3+1)

if __name__ == '__main__':
	# asks for the user to input the endpoint
	end = int(input('input endpoint: '))

	#prints collatz numbers of every integer in range [0, endpoint]
	for i in range(end):
    		print(getCollatz(i+1))
