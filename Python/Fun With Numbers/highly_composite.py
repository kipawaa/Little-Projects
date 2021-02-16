from factors import get_factors

def is_highly_composite(num):
	num_factors = len(get_factors(num))
	for i in range(num-1):
		if len(get_factors(i)) >= num_factors:
			return False
	return True

if __name__ == '__main__':
    mode = int(input("choose a mode:\nbatch mode: 0\nsingle mode: 1\n"))
    
    """ batch mode """
    if mode == 0:
        start = int(input("input the start number: "))
        end = int(input("input the end number: "))
        
        for i in range(start, end + 1):
            if is_highly_composite(i):
                print(f"{i} is highly composite")
            else: print(f"{i} is not highly composite")

    if mode == 1:
        num = 1
        while num >= 0:
            num = int(input("input a number (or -1 to quit): "))
            if is_highly_composite(num):
                print(f"{num} is highly composite")
            else: print(f"{num} is not highly composite")

