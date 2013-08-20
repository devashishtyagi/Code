from random import *

f = open("test.in", "w")

n = 2000

for x in xrange(n):
    f.write(str(randint(-10000, 10000)) + " " + str(randint(-10000, 10000)));
    f.write("\n")

f.close()
