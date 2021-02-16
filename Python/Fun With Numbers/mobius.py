rom prime_decomposition import get_prime_decomposition

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
    mode = int(input("choose a mode:\nbatch mode: 0\nsingle mode: 1\n"))
    
    """ batch mode """
    if mode == 0:
        start = int(input("input the start number: "))
        end = int(input("input the end number: "))
        
        for i in range(start, end + 1):
            print(f"\u03BC({i}) = {mobius(i)}")

    if mode == 1:
        num = 1
        while num >= 0:
            num = int(input("input a number (or -1 to quit): "))
            print(f"\u03BC({num}) = {mobius(num)}")

