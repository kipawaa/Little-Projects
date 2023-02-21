"""
This program uses the ratio of two integers to estimate e using a generator, yielding at every ratio that is a better approximation than the previous
"""

from math import e

def estimate(x=1, y=1):
    previous = x/y
    current = x/y

    while True:
        while abs(e - previous) <= abs(e - current):
            print(f"{x}, {y}: {abs(e-previous)} <= {abs(e - current)}")
            if e - current >= 0:
                x += 1
            else:
                y += 1
            current = x/y
        yield [current, x, y]

if __name__ == "__main__":
    result = next(estimate())
    while (input("hit enter to generate, q to quit: ") != 'q'):
        result = next(estimate(result[1], result[2]))
        print(f"{result[0]} = {result[1]} / {result[2]}")
