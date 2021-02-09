from factors import *

def phi(n):
    return sum([1 for i in range(n + 1) if set(get_factors(i)) & set(get_factors(n)) == {1}])

if __name__ == '__main__':
    start = int(input("input the start number: "))
    end = int(input("input the end number: "))

    for i in range(start, end):
        print(f"numbers relatively prime to {i}: {phi(i)}")
