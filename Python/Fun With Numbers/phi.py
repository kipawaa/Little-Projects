from factors import *

def phi(n):
    return sum([1 for i in range(n + 1) if set(get_factors(i)) & set(get_factors(n)) == {1}])

if __name__ == '__main__':
    mode = int(input("choose a mode:\nbatch mode: 0\nsingle mode: 1\n"))
    
    """ batch mode """
    if mode == 0:
        start = int(input("input the start number: "))
        end = int(input("input the end number: "))
        
        for i in range(start, end + 1):
            print(f"\u03C6({i}) = {phi(i)}")

    if mode == 1:
        num = 1
        while num >= 0:
            num = int(input("input a number (or -1 to quit): "))
            print(f"\u03C6({num}) = {phi(num)}")
