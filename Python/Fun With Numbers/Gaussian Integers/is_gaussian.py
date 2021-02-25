from colours import *

def is_gaussian(num):
    return num.real % 1 == 0 and num.imag % 1 == 0


if __name__ == '__main__':
    num = complex(0, 0)
    while True:
        num = input("input a number (with j in place of i) or q to quit: ")
        try:
            num = complex(num)
            if is_gaussian(num): print(f"{num} is gaussian")
            else: print(f"{num} is not gaussian")
        except:
            if num == 'q':
                break;
            else:
                print(f"{BRED}error{END}: input was not a complex number")
