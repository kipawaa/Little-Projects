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
    while True:
        print("enter two different numbers to perform the euclidian algorithm, or q as either number to quit:")
        num1 = input("number one: ")
        num2 = input("number two: ")
        try:
            num1 = int(num1)
            num2 = int(num2)
            euclidian(num1, num2)
        except:
            if num1 == 'q' or num2 == 'q': break
            if not isinstance(num1, int): print(f"error: {num1} is not an integer")
            if not isinstance(num2, int): print(f"error: {num2} is not an integer")
