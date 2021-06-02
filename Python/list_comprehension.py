def divSeven():
	''' returns the numbers 1-1000 that are divisible by 7 '''
	return [i for i in range(1000) if i % 7 == 0]

def containsThree():
	''' returns the numbers 1-1000 that contain a 3 '''
	return [i for i in range(1000) if '3' in str(i)]

def countSpaces(string):
	''' returns the number of spaces in string '''
	return sum([1 for i in range(len(string)) if string[i] == ' '])

def removeVowels(string):
	''' returns string without the vowels '''
	return ''.join([i for i in string if i not in 'aeiou'])

def findShortWords(string):
	''' returns a list of all the words in string with less than four characters '''
	return [word for word in string.split(' ') if len(word) < 4]

def lengthsOfWords(string):
	''' returns a list of the lengths of all the words in string '''
	return [len(i) for i in string.split(' ')]

def divisibleBy():
	''' returns a nested list of the numbers from 0-1000 divisible by the lists index + 1 '''
	return [[i for i in range(1000) if i % j == 0] for j in range(2, 10)]

def highestDigitDivisor():
	''' returns the highest single digit divisor of each number 1-1000 '''
	return [max([i for i in range(1, 10) if j % i == 0]) for j in range(1000)]

if __name__ == '__main__':
	print(highestDigitDivisor())
	print(lengthsOfWords('once upon a time'))
