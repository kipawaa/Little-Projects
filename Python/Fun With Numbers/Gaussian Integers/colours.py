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
BGGRAY = '\xb1[100m'
BBGRED = '\xb1[101m'
BBGGREEN = '\xb1[102m'
BBGYELLOW = '\xb1[103m'
BBGBLUE = '\xb1[104m'
BBGMAGENTA = '\xb1[105m'
BBGCYAN = '\xb1[106m'
BBGWHITE = '\xb1[107m'
