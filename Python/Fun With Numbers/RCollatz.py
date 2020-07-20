def getCollatz(num:int) -> int:
    if num == 1:
        return 1
    else:
        if num%2 == 0:
            return getCollatz(num//2)
        else:
            return getCollatz(num*3+1)

end = int(input('input endpoint: '))
for i in range(end):
    print(getCollatz(i+1))
