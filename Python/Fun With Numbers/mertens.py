from mobius import *

def mertens(n):
    return sum((mobius(i) for i in range(n + 1)))


if __name__ == '__main__':
    start = int(input("input the start number (inclusive): "))
    end = int(input("input the end number (inclusive): "))
    for i in range(start, end+1):
        print(f"mertens({i}) = {mertens(i)}")
