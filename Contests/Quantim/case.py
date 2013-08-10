import random
import string

X = 2000
S = ''.join(random.choice(string.lowercase) for x in xrange(X))
K = random.randrange(1, len(S))
print K
print S