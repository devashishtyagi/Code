for v in range(input()):
	print "%.15f"%sum([(-1)**x/float(2*x+1)for x in range(input())])