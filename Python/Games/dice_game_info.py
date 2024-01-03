

"""
KNOWN INFORMATION
total number of possible rolls: 46656
"""

def getAllRolls():
    for a in range(1, 7):
        for b in range(1, 7):
            for c in range(1, 7):
                for d in range(1, 7):
                    for e in range(1, 7):
                        for f in range(1, 7):
                            rolls.append([a, b, c, d, e, f])
    return rolls

    
if __name__ == "__main__":
    rolls = getAllRolls()
    # regardless of first roll it is possible to get 30

