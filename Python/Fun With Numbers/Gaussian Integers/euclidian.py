from norm import *
from colours import *

def gaussian_euclidian(a, b):
    q = complex(round((a.real * b.real + a.imag * b.imag) / (b.real**2 + b.imag**2)), round((a.imag * b.real - a.real * b.imag) / (b.real**2 + b.imag**2)))
    r = a - q * b
    print(f"{a} = {q}{b} + {r}")
    while (r != 0):
        a = b
        b = r
        q = complex(round((a.real * b.real + a.imag * b.imag) / (b.real**2 + b.imag**2)), round((a.imag * b.real - a.real * b.imag) / (b.real**2 + b.imag**2)))
        r = a - q * b
        print(f"{a} = {q}{b} + {r}")
    return b

if __name__ == '__main__':
    while True:
        try:
            a = input("input a complex number (or q to quit): ")
            a = complex(a)
            
            b = input("input a complex number (or q to quit): ")
            b = complex(b)
            
            print(f"the gcd is {gaussian_euclidian(a, b)}")
        except:
            if a == 'q' or b == 'q': break # quit condition
            elif b == 0: print(f"{BRED}error{END}: cannot divide by zero") # division by zero
            elif (not isinstance(a, complex)) or (not isinstance(b, complex)): print(f"{BRED}error{END}: inputs must be complex numbers with j in place of i") # complex conversion error
            elif norm(a) < norm(b): print(f"{BRED}norm{END}: of first number must be greater than norm of second number") # dividing by larger number error
            else: print(f"{BRED}error{END}: unknown error") # unknown error catch-all
