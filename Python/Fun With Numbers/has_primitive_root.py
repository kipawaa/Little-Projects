from primes import is_prime
from prime_decomposition import get_prime_decomp_fast

def has_primitive_root(n):
    pd = get_prime_decomp_fast(n)
    if is_prime(n):
        print("is prime")
        return True
    if n == 2 or n == 4:
        print("2, 4")
        return True
    if len(set(pd)) == 1 and pd[1] != 2:
        print("prime power")
        return True
    if pd.count(2) == 1 and len(set(pd)) == 2: # clean
        print("(2 x) prime power")
        return True
    return False

if __name__ == "__main__":
    user = int(input("input a number to find if it has primitive roots: "))
    print(has_primitive_root(user))
