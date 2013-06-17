L = [-1]*1000002
S = [-1]*1000002

i = 1
n = 1
L[n] = 0
S[0] = 1

while(n < 1000002):
    n = 2*n
    num = int("".join(sorted(str(n))))
    if (L[num] == -1):
        L[num] = i;
        n = num
        i += 1
        S[i] = n
    else:
        print "cycle found"
        print num
        print i
        print L[num]

        ans = ""
        for x in xrange(i+1):
            ans =  ans+","+str(S[x])

        print ans

        break
