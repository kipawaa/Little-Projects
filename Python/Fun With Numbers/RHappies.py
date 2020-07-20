MAX = 500
def isHappy(num:int, numLoops:int = 0):
    n = sum(int(digit)**2 for digit in str(num))
    if n == 1:
        return True
    elif numLoops > MAX:
        return False
    else:
        return isHappy(n, numLoops+1)
