from math import ceil, sqrt

def is_prime(n):
    for i in range(2, ceil(sqrt(n))):
        if n % i == 0: return False
    return True
