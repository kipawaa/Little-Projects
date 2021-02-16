# collatz number calculator
# takes user input and determines the collatz number of all integers up to the input number

# determines the collatz number of 'num'
def get_collatz(num:int, numSteps:int=0) -> int:
    if num == 1:
        return numSteps
    else:
        return get_collatz(num//2, numSteps + 1) if num % 2 == 0 else get_collatz(num * 3 + 1, numSteps + 1)

if __name__ == '__main__':
    mode = int(input("choose a mode:\nbatch mode: 0\nsingle mode: 1\n"))
    
    """ batch mode """
    if mode == 0:
        start = int(input("input the start number (n > 0): "))
        end = int(input("input the end number: "))
        
        for i in range(start, end + 1):
            print(f"{i} has collatz number: {get_collatz(i)}")

    """ single mode """
    if mode == 1:
        num = 1
        while num >= 0:
            num = int(input("input a number (or -1 to quit): "))
            print(f"{num} has collatz number: {get_collatz(num)}")
