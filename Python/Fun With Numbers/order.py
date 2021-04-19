from phi import phi

def order(a, n):
    """ returns the order of a mod n
    precondition: a and n are coprime
    """
    for k in range(1, phi(n)):
        if pow(a, k, n) == 1:
            return k
    return phi(n)
