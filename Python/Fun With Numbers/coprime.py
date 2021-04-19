from prime_factors import get_prime_factors
from euclidian_alg import euclidian

def are_coprime(a, b):
    """ returns true if a and b are coprime """
    if a == 0 or b == 0: return False

    M = max(a, b)
    m = min(a, b)
    return euclidian(M, m) == 1
    
