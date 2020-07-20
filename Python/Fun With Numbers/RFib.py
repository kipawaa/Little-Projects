# Return the nth term of the fibonacci sequence, with the sequence starting: 0, 1, 1, 2...
import time

start = time.time()

dictionary = {1:0, 2: 1}

def memoizedFib(n:int) -> int:
	if n in dictionary:
		return dictionary[n]
	else:
		a = memoizedFib(n-1) + memoizedFib(n-2)
		dictionary[n] = a
		del dictionary[n-2]
		return a

if __name__ == '__main__':
	end = int(input('state the term number of interest: '))
	for i in range(end):
		if i % 900 == 0:
			memoizedFib(i+1)
			print(i+1)
	print(memoizedFib(end))
	endtime = time.time()
	print(end, "th term took", endtime-start, "s")
