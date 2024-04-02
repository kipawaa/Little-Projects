def get_gaussian_divisors(n):
    divs = []

    for x in range(-30, 31, 1):
        for y in range(-30, 31, 1):
            if not (x == 0 and y == 0):
                d = complex(x, y)
                r = 30 / d
                if int(r.real) == r.real and int(r.imag) == r.imag:
                    divs.append(d)
    return divs

if __name__ == "__main__":
    user = 0

    while (user != "q"):
        user = input("input a number to find it's gaussian divisors: ")
        try:
            user = complex(user)
            divs = get_gaussian_divisors(user)
            print(f"{user} has {len(set(divs))} gaussian divisors:")
            for div in divs:
                print(div)
        except:
            print("please provide valid input")
