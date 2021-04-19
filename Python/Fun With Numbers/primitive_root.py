from coprime import are_coprime
from phi import phi
from order import order

def get_primitive_roots(n):
    """ returns a list of all primitive roots mod n """
    rrs = [i for i in range(n) if are_coprime(i, n)]
    
    roots = set(rrs)

    phi_n = phi(n)

    for e in rrs:
        if order(e, n) != phi_n:
            roots -= set([e])

    return roots


if __name__ == "__main__":
    user = "a"
    while (user != "q"):
        user = input("input a number to find it's primitive roots: ")
        try:
            user = int(user)
            print(get_primitive_roots(user))
        except ValueError:
            print("please provide valid input")
