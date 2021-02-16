# recursive algorithm for factorial number generation

def get_factorial(num:int) -> int:
	return 1 if num < 1 else num * get_factorial(num - 1)

if __name__ == '__main__':
    mode = int(input("choose a mode:\nbatch mode: 0\nsingle mode: 1\n"))
    
    """ batch mode """
    if mode == 0:
        start = int(input("input the start number: "))
        end = int(input("input the end number: "))
        
        for i in range(start, end + 1):
            print(f"{i}! = {get_factorial(i)}")

    if mode == 1:
        num = 1
        while num >= 0:
            num = int(input("input a number (or -1 to quit): "))
            print(f"{num}! = {get_factorial(num)}")

