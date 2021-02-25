def gaussian_euclidian(a, b):
    q = complex(round((a.real * b.real + a.imag * b.imag) / (b.real**2 * b.imag**2)), round((a.imag * b.real - a.real * b.imag) / (b.real**2 + b.imag**2)))
    r = a - q * b
    print(f"{a} = {q}{b} + {r}")
    while (r != 0):
        print(f"{a} = {q}{b} + {r}")
        a = q
        b = r
        q = complex(round((a.real * b.real + a.imag * b.imag) / (b.real**2 * b.imag**2)), round((a.imag * b.real - a.real * b.imag) / (b.real**2 + b.imag**2)))
        r = a - q * b
    return q

if __name__ == '__main__':
    while True:
        try:
            a = complex(input("input a complex number: "))
            b = complex(input("input a complex number: "))
            gaussian_euclidian(a, b)
        except:
            if b == 0: print("cannot divide by zero")
            if a == b: break;
            if a < b: print("norm of first number must be greater than norm of second number")
