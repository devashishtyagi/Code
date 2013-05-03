import numpy

fp = open('output.txt', 'r')

a = numpy.empty((20,10000), dtype = int)
b = numpy.empty((2,10000), dtype = int)

for i in xrange(10000):
	b[0][i] = 1;
b[0][10000-1] = 0

i = 0
for lines in fp:
	lines = lines.strip()
	data = lines.split()
	for j in xrange(len(data)):
		a[i][j] = int(data[j])
		if (j == 10000-7):
			print a[i][j]
	i = i+1

fp.close()

for i in xrange(20):
	prev = i%2;
	curr = (i+1)%2;
	for j in xrange(6,7):
		# print b[prev][a[i][j]-1],' ',a[i][j] 
		b[curr][j] = b[prev][j] + b[prev][a[i][j]-1]

# for i in xrange(10000):
# 	print(int(b[1][i]))
# print('\n')