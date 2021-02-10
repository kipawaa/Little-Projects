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



if __name__ == '__main__':
    # sample inputs:
    #   1 + 2
    #   (1 - 4) * 2
    #   1 / (4 * (3 + 2))
    import doctest
    doctest.testmod(verbose=True)
