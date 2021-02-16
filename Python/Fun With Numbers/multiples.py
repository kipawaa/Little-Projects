from prime_decomposition import *

def get_GCD(a, b):
    """ returns the Greatest Common Divisor of a and b
    
    Precondition:
        a is an integer
        b is an integer
    """
    a_primes = get_prime_decomposition(a)
    b_primes = get_prime_decomposition(b)

    shared_primes = set(a_primes) & set(b_primes)
    
    # GCD = product of the shared prime factors with multiplicty = to the lesser multiplicity in the numbers
    return product([i ** min(a_primes.count(i), b_primes.count(i)) for i in shared_primes])

    
def get_LCM(a, b):
    """ returns the Least Common Multiple of a and b
        
    Precondition:
        a is an integer
        b is an integer
    """
    a_primes = get_prime_decomposition(a)
    b_primes = get_prime_decomposition(b)
    
    all_primes = set(a_primes) | set(b_primes)

    # LCM = product of the shared prime factors with multiplicty = to the greater mutltiplicity in the numbers
    return product([i ** max(a_primes.count(i), b_primes.count(i)) for i in all_primes])
    

if __name__ == '__main__':
    a = 0
    b = 1
    while a != b:
        a = int(input("input the first number: "))
        b = int(input("input the second number (or the same as the first number to quit): "))

        print(f'the GCD of {a} and {b} is {get_GCD(a, b)}')
        print(f'the LCM of {a} and {b} is {get_LCM(a, b)}')
