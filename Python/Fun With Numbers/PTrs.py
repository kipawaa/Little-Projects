# finds pythagorean triples up to n

def is_PTr(a, b, c):
    return a + b == c

if __name__ == "__main__":
    n = int(input("find pythagorean triples with sidelengths up to: "))

    squares = [i**2 for i in range(1, n)]

    print(squares)

    PTRs = []
    
    for c in range(0, n-1):
        for b in range(0, n-1):
            if (b < c):
                for a in range(0, n-1):
                    if (a <= b):
                        if (is_PTr(squares[a], squares[b], squares[c])):
                            PTRs.append([a+1, b+1, c+1])

    for PTr in PTRs:
        print(PTr)
