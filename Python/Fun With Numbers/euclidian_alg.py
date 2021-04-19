from colours import *

def print_euclidian(num, divisor):
    remainder = num % divisor
    multiplier = num // divisor
    print(f"{num} = {divisor}({multiplier}) + {remainder}")
    while (remainder != 0):
        num = divisor
        divisor = remainder
        remainder = num % divisor
        multiplier = num // divisor
        print(f"{num} = {divisor}({multiplier}) + {remainder}")


def euclidian(num, divisor):
    remainder = num % divisor
    multiplier = num // divisor
    while remainder != 0:
        num = divisor
        divisor = remainder
        remainder = num % divisor
        multiplier = num // divisor
    return divisor


if __name__ == '__main__':
    while True:
        print("enter two different numbers to perform the euclidian algorithm, or q as either number to quit:")
        num1 = input("number one: ")
        num2 = input("number two: ")
        try:
            num1 = int(num1)
            num2 = int(num2)
            print(euclidian(num1, num2))
        except:
            if num1 == 'q' or num2 == 'q': 
                print("program closed.")
                break
            elif not isinstance(num1, int): print(f"{RED}error{END}: {num1} is not an integer")
            elif not isinstance(num2, int): print(f"{RED}error{END}: {num2} is not an integer")
            else: print("generic error")
