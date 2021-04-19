""" this version works using the other programs in this directory """
from prime_factors import get_prime_factors

def product(lst):
    total = 1
    for i in lst:
        total *= i
    return total


def get_prime_decomposition(n):
    factors = get_prime_factors(n)

    while product(factors) < n:
        newFactors = get_prime_factors(n // product(factors))
        factors.extend(newFactors)

    factors.sort()

    return factors


def get_prime_decomp_fast(num):
    decomp = []

    div = 2
    
    while num > 1:
        if num % div == 0:
            num /= div
            decomp.append(div)
        else:
            div += 1

    return decomp


""" This version uses a simple while loop """
def simple_prime_decomp(num):
    factors = []

    div = 2
    while num > 1:
        if num % div == 0:
            factors.append(div)
            num /= div;
        else:
            div += 1

    return factors

""" this version uses the some logic as the above, but is recursive """
def recursive_prime_decomp(num, factors=[]):
    if num <= 1:
        return factors

    div = 2
    while num % div != 0:
        div += 1

    factors.append(div)
    
    return recursive_prime_decomp(num/div, factors)



if __name__ == '__main__':
    mode = int(input("choose a mode:\nbatch mode: 0\nsingle mode: 1\n"))
    
    """ batch mode """
    if mode == 0:
        start = int(input("input the start number: "))
        end = int(input("input the end number: "))
        
        for i in range(start, end + 1):
            print(f"{i} has prime decomposition: {get_prime_decomposition(i)}")
            print(f"recursive: {recursive_prime_decomp(i, [])}")
            print(f"loop: {simple_prime_decomp(i)}")

    if mode == 1:
        num = 1
        while num >= 0:
            num = int(input("input a number (or -1 to quit): "))
            print(f"{num} has prime decomposition: {get_prime_decomposition(num)}")
