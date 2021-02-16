def isHappy(num:int, maxLoops:int=995, numLoops:int = 0):
    n = sum([int(digit)**2 for digit in str(num)])
    if n == 1:
        return True
    elif numLoops > maxLoops:
        return False
    else:
        return isHappy(n, maxLoops, numLoops+1)

if __name__ == '__main__':
    mode = int(input("choose a mode:\nbatch mode: 0\nsingle mode: 1\n"))
    
    """ batch mode """
    if mode == 0:
        start = int(input("input the start number: "))
        end = int(input("input the end number: "))
        
        for i in range(start, end + 1):
            if isHappy(i):
                print(f"{i} is a happy number!")
            else: print(f"{i} is not a happy number :(")

    if mode == 1:
        num = 1
        while num >= 0:
            num = int(input("input a number (or -1 to quit): "))
            if num > 0 and isHappy(num):
                print(f"{num} is a happy number!")
            else: print(f"{num} is not a happy number :(")

