# contains strings defining ANSI codes for colours and effects

# sequence to end ANSI effects
END = '\x1b[0m'

"""-------------------------------TEXT COLOURS-------------------------------"""
# Regular text colours
BLACK = '\x1b[30m'
RED = '\x1b[31m'
GREEN = '\x1b[32m'
YELLOW = '\x1b[33m'
BLUE = '\x1b[34m'
MAGENTA = '\x1b[35m'
CYAN = '\x1b[36m'
WHITE = '\xb1[37m'

# Bright text colours
GRAY = '\xb1[90m'
BRED = '\x1b[91m'
BGREEN = '\x1b[92m'
BYELLOW = '\x1b[93m'
BBLUE = '\x1b[94m'
BMAGENTA = '\x1b[95m'
BCYAN = '\x1b[96m'
BWHITE = '\xb1[97m'


"""----------------------------BACKGROUND COLOURS----------------------------"""
# Regular background colours
BGBLACK = '\x1b[40m'
BGRED = '\x1b[41m'
BGGREEN = '\x1b[42m'
BGYELLOW = '\x1b[43m'
BGBLUE = '\x1b[44m'
BGMAGENTA = '\x1b[45m'
BGCYAN = '\x1b[46m'
BGWHITE = '\x1b[47m0'

# Bright background colours
BGGRAY = '\x1b[100m'
BBGRED = '\x1b[101m'
BBGGREEN = '\x1b[102m'
BBGYELLOW = '\x1b[103m'
BBGBLUE = '\x1b[104m'
BBGMAGENTA = '\x1b[105m'
BBGCYAN = '\x1b[106m'
BBGWHITE = '\x1b[107m'


# 0 - 8 text modifiers (italics, blinking etc)
# 30-37 text colours
# 40-47 background colours
# 90-97 text colours
# 100-107 background colours

if __name__ == '__main__':
    sequence = "\x1b["
    print("modifiers:")
    for i in range(8):
        print(f"{sequence}{i}m this is what \\x1b[{i}m looks like {END}")

    print("text colours:")
    for i in range(30, 38):
        print(f"{sequence}{i}m this is what \\x1b[{i}m looks like {END}")
    for i in range(90, 98):
        print(f"{sequence}{i}m this is what \\x1b[{i}m looks like {END}")

    print("background colours:")
    for i in range(40, 48):
        print(f"{sequence}{i}m this is what \\x1b[{i}m looks like {END}")
    for i in range(100, 108):
        print(f"{sequence}{i}m this is what \\x1b[{i}m looks like {END}")
