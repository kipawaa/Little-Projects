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


def evaluate_brackets(string):
    # TODO replace eval with my own function. 
    # Function only needs to be able to evaluate operations of the form '<val> <operation> <val>'
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
            string = string[:start] + str(eval(string[start : i + 1])) + string[i + 1:]
            i = start + 1
        i += 1
    return int(string)


if __name__ == '__main__':
    # sample inputs:
    #   1 + 2
    #   (1 - 4) * 2
    #   1 / (4 * (3 + 2))

    import doctest
    doctest.testmod(verbose=True)
