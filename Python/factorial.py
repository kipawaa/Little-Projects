#contains recursive and looping factorial finders

def recursive_factorial_finder(n):
    return 1 if n == 1 else n * recursive_factorial_finder(n - 1)
    
def looping_factorial_finder(n):
    total = 1
    for i in range(1, n+1):
        total *= i
    return total

if __name__ == '__main__':
	term_number = int(input("input your number to factorial: "))
	print(recursive_factorial_finder(term_number));
