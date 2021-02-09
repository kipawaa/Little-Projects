from factors import get_factors

def sigma_k(num, k):
    return sum([i**k for i in get_factors(num)])


if __name__ == '__main__':
    print("enter a number to perform sigma_k on:")
    num = int(input("number: "))
    k = int(input("k: "))
    print(sigma_k(num, k))
