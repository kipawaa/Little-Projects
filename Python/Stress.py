# uses the multiprocessing library to stress each cpu thread, attempting to sum many many random numbers
import random
import multiprocessing as mp

# CHANGE THIS to test your own computer!
numThreads = 6;

# function that takes a queue and adds the task of summing many many random numbers to that queue
def randomNumber(q):
    total = 0
    for i in range(100000000000):
    	total += random.random()
    q.put(total)

if __name__ == '__main__':
	# honestly not sure what exactly this does but it was in the tutorial and is required
	mp.set_start_method('spawn')

	# creates the queue that will hold tasks for the threads
	q = mp.Queue()
	processes = []
	for i in range(numThreads):
		processes.append(mp.Process(target=randomNumber, args=(q,)))

	# begins all the tasks
	for i in processes:
		i.start()

	# requests the sum of the numbers generated
	total = 0
	for i in processes:
		total += q.get()	
		print(total)
    
    	# cleans up everything once it's complete
	for i in processes:
		i.join()
		i.close()
