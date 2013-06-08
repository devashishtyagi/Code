def gcd(a, b):
	if (a > b):
		return gcd(b, a)
	elif (a == 0):
		return b;
	else:
		return gcd(b%a, a)

def calculate(A):
	p = 0
	q = 1
	for a in reversed(A):
		p = a*q + p;
		g = gcd(p, q)
		p = p/g
		q = q/g
		p, q = q, p
	return q,p

def start():
	line = raw_input()
	data = line.split()
	p = long(data[0])
	q = long(data[1])
	n = int(raw_input())
	A = []
	line = raw_input()
	data = line.split()
	for i in xrange(n):
		A.append(long(data[i]))
	g = gcd(p, q)
	p = p/g
	q = q/g
	r, s = calculate(A)
	#print r, s
	if (p == r and q == s):
		print "YES"
	else:
		print "NO"

start()