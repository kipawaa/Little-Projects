#returns true if the binary string num is divisible by divisor, otherwise false
def binaryDivision(num:int, divisor:int) -> bool:
    return bint(num)%divisor == 0


#returns the int version of num, which is a binary string
def bint(num:str) -> int:
    num = num[::-1]
    total = 0
    for i in range(len(num)):
        if num[i] == '1':
            total += 2**i
    return total
