from cmath import *
def is_gaussian(num):
    return num.real % 1 == 0 and num.imag % 1 == 0

if __name__ == '__main__':
    try:
        num = complex(input("input a number (with j in place of i): "))   
        
        while isinstance(num, complex):
            if is_gaussian(num): print(f"{num} is gaussian")
            else: print(f"{num} is not gaussian")
            num = complex(input("input a number (with j in place of i): "))
    except:
        RED = '\033[91m'
        ENDCOLOUR = '\033[0m'
        print(f"{RED}error{ENDCOLOUR}: input was not a complex number")
