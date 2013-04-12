import random

file = open('test.in', 'w');
file.write('1\n')
file.write('6666 5\n')

random.seed(34329)

for i in xrange(6666):
	for j in xrange(5):
		a = random.randint(-100000000, 100000000)
		file.write(str(a)+' ')
	file.write('\n')
