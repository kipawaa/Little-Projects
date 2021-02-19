"""
calculator program for simple number computations.

TODO:
    a function to add brackets to bracketless expressions (i.e. convert '1 + 2' to '(1 + 2)')
"""

def check_brackets(string: str) -> bool:
    ''' Return True if string has proper bracketing

    >>> check_brackets('(1+2)/3')
    True
    >>> check_brackets(')(')
    False
    '''
    num_single_brackets = 0
    for char in string:
        # update the number of lone brackets
        if char == '(':
            num_single_brackets += 1
        elif char == ')':
            num_single_brackets -= 1
        
        # ensure we never have more right brackets than left brackets
        if num_single_brackets < 0:
            return False
    
    # ensure we end with 0 brackets lone brackets
    return num_single_brackets == 0


def perform_operation(string):
    """ takes a string of the form '<val> <operator> <val>' and returns the result of evaluation
    
    >>> perform_operation('1 + 2')
    3
    >>> perform_operation('4 * 6')
    24
    >>> perform_operation('9 / 3')
    3.0
    """

    string.strip()
    
    val1 = float(string[0:string.index(' ')].strip())
    
    # remove val1 and the space from the string
    string = string[string.index(' ') + 1:]
    
    operator = string[0:string.index(' ')]
    
    # remove the operator from the string
    string = string[string.index(' '):]
    
    val2 = float(string.strip())

    if (operator == '+'):
        return val1 + val2
    if (operator == '-'):
        return val1 - val2
    if (operator == '*'):
        return val1 * val2
    if (operator == '/'):
        return val1 / val2


def evaluate_brackets(string):
    """ evaluate a mathematical expression with full bracketing

    >>> evaluate_brackets('(1 + 2)')
    3
    >>> evaluate_brackets('(2 + (3 * 4))')
    14
    """

    brackets = []
    i = 0
    while i < len(string):
        if string[i] == '(':
            brackets.append(i)
        elif string[i] == ')':
            # evaluate everything from brackets.pop to i
            start = brackets.pop()
            string = string[:start] + str(perform_operation(string[start+1 : i])) + string[i + 1:]
            i = start + 1
        i += 1
    return float(string)


def calculate(string):
    if not check_brackets(string):
        print("brackets are wrong!!!")
        return -1
    else:
        return evaluate_brackets(string)


if __name__ == '__main__':
    # sample inputs:
    #   1 + 2
    #   (1 - 4) * 2
    #   1 / (4 * (3 + 2))

    import doctest
    doctest.testmod(verbose=True)
