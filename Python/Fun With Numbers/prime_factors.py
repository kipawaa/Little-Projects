from factors import get_factors
from primes import is_prime


def get_prime_factors(num):
    return [factor for factor in get_factors(num) if is_prime(factor)]


if __name__ == '__main__':
    mode = int(input("choose a mode:\nbatch mode: 0\nsingle mode: 1\n"))
    
    """ batch mode """
    if mode == 0:
        start = int(input("input the start number: "))
        end = int(input("input the end number: "))
        
        for i in range(start, end + 1):
            print(f"{i} has prime factors: {get_prime_factors(i)}")

    if mode == 1:
        num = 1
        while num >= 0:
            num = int(input("input a number (or -1 to quit): "))
            print(f"{num} has prime factors: {get_prime_factors(num)}")
