import sympy

F, a, b = sympy.free_group("a, b")
G = sympy.FpGroup(F, [a**2, b**3, (a*b)**4])
G


