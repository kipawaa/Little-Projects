

def get_common_factors(a, b):
    for i in range(1,max(a,b)):
        if 0 == a % i and 0 == b % i:
            print(i)

if __name__ == "__main__":
    print(get_common_factors(100177878790080000, 322764750000))
