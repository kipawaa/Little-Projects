from phi import phi

def order(a, n):
    """ returns the order of a mod n
    precondition: a and n are coprime
    """
    for k in range(1, phi(n)):
        if pow(a, k, n) == 1:
            return k
    return phi(n)


if __name__ == "__main__":
    user = 'a'
    mod = 'b'

    while (user != 'q' and mod != 'q'):
        user = input("input a number to find it's order: ")
        mod = input("input your modulus: ")

        try:
            user = int(user)
            mod = int(user)
            order = order(user, mod)
            print(f"the order of {user} mod {mod} is {order}")
        except:
            print("please provide valid input")
