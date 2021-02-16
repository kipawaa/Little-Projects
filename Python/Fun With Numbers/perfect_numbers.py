from sigma_k import *

def is_perfect(n):
    return sigma_k(n, 1) == 2*n

if __name__ == '__main__':
    mode = int(input("choose a mode:\nbatch mode: 0\nsingle mode: 1\n"))
    
    """ batch mode """
    if mode == 0:
        start = int(input("input the start number: "))
        end = int(input("input the end number: "))
        
        for i in range(start, end + 1):
            if is_perfect(i): print(f"{i} is a perfect number!")
            else: print(f"{i} is not perfect")

    if mode == 1:
        num = 1
        while num >= 0:
            num = int(input("input a number (or -1 to quit): "))
            if num >= 0:
                if is_perfect(num): print(f"{num} is a perfect number!")
                else: print(f"{num} is not perfect")
