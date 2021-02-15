from factors import get_factors

def sigma_k(num, k):
    return sum([i**k for i in get_factors(num)])


if __name__ == '__main__':
    mode = int(input("input 0 for batch mode or 1 for single mode: "))

    """ batch mode """
    if mode == 0:
        k = int(input("input k: "))
        start = int(input("input the start number: "))
        end = int(input("input the end number: "))
        for i in range(start, end):
            print(f"sigma_{k}({i}) = {sigma_k(i, k)}")
    

    """ single mode """
    if mode == 1:
        print("enter a number to perform sigma_k on:")
        num = int(input("number: "))
        k = int(input("k: "))
        print(sigma_k(num, k))

    """ find max
    most = 0
    for i in range(0, 150000):
        most = max(most, sigma_k(i, -1))

    print(f"the highest value we found was {most}")
    
    """
    

