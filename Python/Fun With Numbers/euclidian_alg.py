
def euclidian(num, divisor):
    remainder = num % divisor
    multiplier = num // divisor
    print(f"{num} = {divisor}({multiplier}) + {remainder}")
    while (remainder != 0):
        num = divisor
        divisor = remainder
        remainder = num % divisor
        multiplier = num // divisor
        print(f"{num} = {divisor}({multiplier}) + {remainder}")


if __name__ == '__main__':
    num1 = 0
    num2 = 1
    while num1 != num2:
        print("enter two different numbers to perform the euclidian algorithm, or two of the same number to quit:")
        num1 = int(input("number one: "))
        num2 = int(input("number two: "))
        euclidian(num1, num2)
