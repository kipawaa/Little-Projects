from sigma_k import *

def is_perfect(n):
    return sigma_k(n, 1) == 2*n

if __name__ == '__main__':
    start = int(input("input the start number:"))
    end = int(input("input the end number:"))

    for i in range(start, end):
        if is_perfect(i):
            print(f"{i} is perfect!")
