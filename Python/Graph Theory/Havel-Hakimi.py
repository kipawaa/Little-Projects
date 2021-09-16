def havel_hakimi(degseq):
    # degree sequence is valid if it this algorithm reduces it to an isolated graph
    print(degseq)
    if list(filter(lambda x: x != 0, degseq)) == []: return True

    # degree sequence cannot have negative values
    if min(degseq) < 0: return False

    # degree sequence must have even sum
    if sum(degseq) % 2 != 0: return False

    # degree sequence cannot have a degree larger than the number of vertices
    if max(degseq) > len(degseq): return False

    # remove first value
    s = degseq.pop(0)

    # subtract 1 from the first a_1 values
    for i in range(s):
        degseq[i] -= 1

    # now check again
    return havel_hakimi(sorted(degseq, reverse=True))

if __name__ == "__main__":
    import sys
    user = 1

    while (user != "q"):
        user = input("input a degree sequence to test its validity, or q to exit: ")
        try:
            degseq = [int(num.strip()) for num in user.split(',')]
            if havel_hakimi(list(degseq)): # use list() to pass a copy so that original is unmodified
                print(f"{degseq} is a valid degree sequence!")
            else:
                print(f"{degseq} is an invalid degree sequence")
        except (TypeError, ValueError):
            print("please provide valid input")
        except:
            print(sys.exc_info())
