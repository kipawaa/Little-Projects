from math import sqrt, ceil
from tqdm import tqdm

def get_gaussian_divisors(n):
    divs = []

    radius = ceil(sqrt(n.real**2 + n.imag**2))

    for x in tqdm(range(radius+1)):
        for y in range(radius+1):
            if not (x == 0 and y == 0):
                d = complex(x, y)
                r = n / d
                if int(r.real) == r.real and int(r.imag) == r.imag:
                    divs.append(d)
                    divs.append(d*1j)
                    divs.append(-d)
                    divs.append(d*-1j)
    return divs

if __name__ == "__main__":
    user = 0

    while (user != "q"):
        user = input("input a number to find it's gaussian divisors: ")
        #try:
        user = complex(user)
        divs = get_gaussian_divisors(user)
        for div in divs:
            print(div)
        print(f"{user} has {len(set(divs))} gaussian divisors, listed above")
        #except:
        #    print("please provide valid input")
