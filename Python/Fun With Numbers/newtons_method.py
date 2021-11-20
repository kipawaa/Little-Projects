def step(x_0):
    x_n = x_0
    while f(x_n) != 0:
        prev = x_n
        x_n = x_n - f(x_n)/df(x_n)
        if prev == x_n:
            print("values are not changing! we've probably found a solution :)")
        yield x_n


def f(x):
    return x**3 - x - 1

def df(x):
    return 3*x**2 - 1

if __name__ == "__main__":
    x_0 = float(input("input x_0: "))
    generator = step(x_0)
    user = ""

    while user != "q":
        x_n = next(generator)
        print((x_n, f(x_n)))
        user = input("enter to continue, q to quit: ")
