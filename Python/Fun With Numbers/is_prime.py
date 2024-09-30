from math import ceil, sqrt

def is_prime(n):
    for i in range(2, ceil(sqrt(n))+1):
        if n % i == 0: return False
    return True

if __name__ == '__main__':
    mode = int(input("choose a mode:\nbatch mode: 0\nsingle mode: 1\n"))

    """ batch mode """
    if mode == 0:
        start = int(input("input the start number: "))
        end = int(input("input the end number: "))

        for i in range(start, end + 1):
            print(f"{i} is {'not ' if not is_prime(i) else ''}prime")

    if mode == 1:
        num = 1
        while num >= 0:
            num = int(input("input a number (or -1 to quit): "))
            print(f"{num} is {'not ' if not is_prime(num) else ''}prime")
