import random
import multiprocessing as mp

def randomNumber(q):
    nums = [random.random() for i in range(10000000000000000)]
    total = sum(nums)
    q.put(total)

if __name__ == '__main__': 
	mp.set_start_method('spawn')

	q = mp.Queue()
	processes = []
	for i in range(12):
		processes.append(mp.Process(target=randomNumber, args=(q,)))

	for i in processes:
		i.start()

	total = 0
	for i in processes:
		total += q.get()	
		print(total)
    
	for i in processes:
		i.join()
		i.close()
