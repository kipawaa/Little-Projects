from prime_decomposition import get_prime_decomposition

def mobius(n):
    # 1 returns 1
    if n == 1:
        return 1

    primes = get_prime_decomposition(n)
    
    # if we have a prime factor with multiplicity > 1 then return 0
    if len(set(primes)) < len(primes):
        return 0
    
    
    return (-1)**(len(primes))


if __name__ == '__main__':
    start = int(input("input the start number (inclusive): "))
    end = int(input("input the end number (inclusive): "))
    
    for i in range(start, end + 1):
        print(f"\u03BC({i}) = {mobius(i)}")
