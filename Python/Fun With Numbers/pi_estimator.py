from math import sqrt
from decimal import *
from sys import argv

def factorial(x):
    total = Decimal(1)
    for i in range(1, int(x) + 1):
        total *= Decimal(i)
    return total

def approximate():
    # holds the sum
    s = Decimal(0)

    # term number
    k = Decimal(0)

    # constant factor
    c = (Decimal(2) * Decimal(2).sqrt()) / Decimal(9801)

    while True:
        s += (factorial(Decimal(4) * k) * (Decimal(1103) + Decimal(26390) * k)) / ((factorial(k) ** Decimal(4)) * (Decimal(396) ** (Decimal(4) * k)))
        k += Decimal(1)
        #print(f"s: {s}\nk: {k}")
        #print(f"s: {type(s)}\nk: {type(k)}")
        yield [Decimal(1) / (c * s), k]

if __name__ == "__main__":
    # set precision
    getcontext().prec = int(input("input the number of desired decimal places: "))

    generator = approximate()
    
    prev = None
    estimate = 0
    iteration = None
    if (True):
        while (input("hit enter to generate next approximation, or q to quit: ") != 'q'):
            if (estimate):
                prev = estimate
            (estimate, iteration) = next(generator)

            if (prev):
                if (prev.compare(estimate) == 0):
                    print("maximum precision exceeded")
            print(f"{iteration}th estimation of pi is: {estimate}")
    else:
        while(estimate != prev):
            if (estimate):
                prev = estimate
            (estimate, iteration) = next(generator)

            if (prev):
                if (prev.compare(estimate) == 0):
                    print(f"pi = {estimate} obtained after {iteration} iterations")

