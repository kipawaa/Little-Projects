""" solutions to w3resource's lambda expression worksheet """

if __name__ == "__main__":
    # add 15 to a given number
    lambda x : x + 15
    # multiply two numbers
    lambda x, y : x * y
    
    # multiply a number by a currently unknown number
    def foo(n):
        return lambda x : x * n
    
    # sort a list of tuples by the second element
    [('English', 88), ('Science', 90), ('Maths', 97), ('Social sciences', 82)].sort(key = lambda x : x[1])

    # sort a list of dictionaries by a given key ('make')
    [{'make': 'Nokia', 'model': 216, 'color': 'Black'}, {'make': 'Mi Max', 'model': '2', 'color': 'Gold'}, {'make': 'Samsung', 'model': 7, 'color': 'Blue'}].sort(key = lambda d : d['make'])

    # filter out the odd numbers
    list(filter(lambda x : x % 2 == 0, [i for i in range(10)]))

    # square every number of a list
    list(map(lambda x : x**2, [i for i in range(10)]))

    # check if string starts with a given letter ('P')
    lambda x : x[0] == 'P'

    # check if a string is entirely numeric
    lambda x : x[1:].replace('.', '', 1).isnumeric() if x[0] == '-' else x.replace('.', '', 1).isnumeric()

    # find the intersection of two arrays
    list(filter(lambda x : x in [i for i in range(1, 12, 2)], [i for i in range(3, 9)]))

    # separate positive and negative numbers
    sorted([-1, 4, -1, -4, -5, 6, 3, 3, 5, 6], key = lambda x : 1 if x > 0 else -1)

    # count the even numbers in an array
    len(list(filter(lambda x : x % 2 == 0, [i for i in range(10)])))

    # add two lists pairwise
    list(map(lambda x, y : x + y, [i for i in range(1, 5)], [i for i in range(5, 10)]))

    # get list of palindromes from list
    list(filter(lambda x : x == reversed(x), ['php', 'w3r', 'Python', 'abcd', 'Java', 'aaa']))

    # find anagrams of a string in list
    list(filter(lambda x : sorted(x) == 'abcd', ['bcda', 'abce', 'cbda', 'cbea', 'adcb']))

    
