from colours import *

def norm(num):
    return num.real**2 + num.imag**2

if __name__ == '__main__':
    while True:
        try:
            num = input("input a complex number (of the form a+bj) to find its norm, or q to quit: ")
            num = complex(num)
            print(f"N({num}) = {norm(num)}")
        except:
            if num == 'q': break;
            else: print(f"{BRED}error{END}: number must be complex.")
